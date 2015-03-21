// CodeContracts
// 
// Copyright (c) Microsoft Corporation
// 
// All rights reserved. 
// 
// MIT License
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

using System;
using System.Collections.Generic;
using System.IO;
using System.Diagnostics.Contracts;
using System.Diagnostics.CodeAnalysis;

/*
  The algorithm is taken from book "Combinatorial Optimization. Algorithms and Complexity"
  Christos H. Papadimitriou, Kenneth Steigitz
*/

namespace Microsoft.Glee.Optimization
{

  /// <summary>
  /// Keeps the Tableu and the basis
  /// </summary>
  internal class Tableau
  {

    #region Object Invariant
    [ContractInvariantMethod]
    void ObjectInvariant()
    {
      Contract.Invariant(this.length1 >= 0);
      Contract.Invariant(epsilon > 0.0d);  // F: should be inferred
    }
    #endregion

    /// <summary>
    /// the number of constraints
    /// </summary>
    internal int m;
    /// <summary>
    /// the number of vars would be correceted when we get rid of artificials
    /// </summary>
    internal int n;

    /// <summary>
    /// return the tableu matrix
    /// </summary>
    /// <returns></returns>
    internal double[] ReturnMatrix() {
      return matrix; }

    /// <summary>
    /// keeps the values of basis variables
    /// </summary>
    /// <returns></returns>
    internal double[] GetSolution() { return x; }

    /// <summary>
    /// the matrix
    /// </summary>
    internal double[] matrix;

    /// <summary>
    /// values of the vars - equals to the right side values from the beginning
    /// </summary>
    internal double[] x;

    readonly double epsilon = 1.0E-8;

    public double Epsilon
    {
      get
      {
        Contract.Ensures(epsilon > 0.0d);

        return epsilon;
      }
      //            set { epsilon = value; }
    }

    /// <summary>
    ///basis[i] is the basis variable for the i-th constraint 
    /// </summary>
    internal int[] basis; //m is the dimension of the basis



    /// <summary>
    /// characteristic function for basis
    /// basisSet[i] is true when i belongs to the basis
    /// </summary>
    private bool[] basisSet;

    internal bool[] BasisSet
    {
      get { return basisSet; }
      set { basisSet = value; }
    }
    internal int[] ReturnBasis() { return basis; }

    [Pure]
    internal int ReturnLengthOne()
    {
      Contract.Ensures(Contract.Result<int>() >= 0);
      return length1;
    }
    /// <summary>
    /// Here we know the column and we follow Bland's algorith 
    /// by picking the minimal i such that x[i]/X[i,j]=min{x[k]/X[k,j]| k in[0,n-1], X[k,j]>0}
    /// </summary>
    /// <param name="j"></param>
    /// <returns>the row or -1 if cannot choose; means Unbounded </returns>
    internal int ChooseLeavingRow(int j)
    {
      Contract.Ensures(Contract.Result<int>() >= -1);

      int minI = -1;
      double minQ = Single.MaxValue;

      for (int k = 0; k < m; k++)
      {
        double mkj = matrix[k * length1 + j]; ;

        Contract.Assume(mkj != 0.0d); // F: need quantified invariants 

        if (mkj > this.Epsilon)
        {
          double d = x[k] / mkj;
          if (d < minQ)
          {
            minI = k;
            minQ = d;
          }
        }
      }
      return minI;
    }



    internal void PutVarToBasis(int row, int column)
    {
      Contract.Requires(row >= 0);
      Contract.Requires(column >= 0);

      if (basis[row] > -1)
        BasisSet[basis[row]] = false;

      basis[row] = column;

      BasisSet[column] = true;

    }

    /// <summary>
    /// it puts in to the basis the variable X[row,column]
    /// </summary>
    /// <param name="row"></param>
    /// <param name="column"></param>

    [SuppressMessage("Microsoft.Contracts", "TestAlwaysEvaluatingToAConstant")]
    unsafe internal void Pivot(int row, int column)
    {
      Contract.Requires(row >= 0);
      Contract.Requires(column >= 0);

      PutVarToBasis(row, column);

      double d = matrix[row * length1 + column]; //here d must be greate than LP.Epsilon so we don't check it for zero

      Contract.Assume(d > this.Epsilon);

      fixed (double* pinX = &matrix[0])
      {
        double* xrowjStart = pinX + row * length1;
        double* xrowjEnd = xrowjStart + n;

        for (double* xrowj = xrowjStart; xrowj < xrowjEnd; xrowj++)
        {
          Contract.Assert(d != 0.0d);

          (*xrowj) /= d;
        }
        double xrow = x[row] /= d;
        double* xij = pinX;
        double* xicol = xij + column;
        int length1MinusN = length1 - n;

        fixed (double* pinxi = x)
        {
          double* xi = pinxi;
          double* xiend = xi + m;
          double* xirow = xi + row;
          for (; xi < xiend; xicol += length1, xi++)
          {
            if (xi == xirow) { xij += length1; continue; }

            double a = *xicol;
            for (double* xrowj = xrowjStart; xrowj < xrowjEnd; xij++, xrowj++)
              (*xij) -= a * (*xrowj);

            xij += length1MinusN;

            (*xi) -= a * xrow;
          }
        }
      }
    }


    /// <summary>
    /// calculate reduced costs corresponding to the basis
    /// </summary>
    /// <param name="c">costs</param>
    /// <param name="rc">reduced costs</param>
    unsafe internal void CalcReducedCosts(double[] c, double[] rc)
    {

      fixed (bool* basisSetjp = BasisSet)
      {
        bool* basisSetj = basisSetjp;
        fixed (double* pinX = matrix)
        {
          double* x0j = pinX;
          fixed (int* pinbasis = basis)
          {
            int* basisend = pinbasis + m;

            fixed (double* pinrc = rc)
            {
              fixed (double* pinc = c)
              {
                double* rcj = pinrc;
                double* pincj = pinc;
                double* pincjend = pinc + n;
                for (; pincj < pincjend; x0j++)
                {
                  if (*(basisSetj++))
                  {//the other branch would give zero anyway but this is more efficient
                    *(rcj++) = 0;
                    pincj++;
                  }
                  else
                  {
                    double r = *(pincj++);

                    double* xij = x0j;
                    int* basisi = pinbasis;
                    for (; basisi < basisend; xij += length1)
                    {
                      Contract.Assume(*(basisi) >= 0);
                      Contract.Assume(*(basisi) < c.Length);
                      r -= (c[*(basisi++)] * (*xij));
                    }
                    *(rcj++) = r;
                  }
                }
              }
            }
          }
        }
      }
    }
    /// <summary>
    /// puts the first column in to basis vars
    /// </summary>
    /// <returns></returns>
    internal double[] GetSolution(int nVars)
    {
      Contract.Requires(nVars >= 0);

      double[] ret = new double[nVars];
      for (int i = 0; i < m; i++)
      {
        int j = basis[i];
        if (j < nVars)
          ret[j] = this.x[i];
      }

      return ret;

    }

    int length1;
    internal void UpdateMatrix(double[] parX, int lengthZero, int lengthOne)
    {
      Contract.Requires(lengthZero >= 0);
      Contract.Requires(lengthOne >= 0);

      matrix = parX;
      m = lengthZero;
      n = lengthOne;
      basis = new int[m];
      for (int i = 0; i < m; i++)
        basis[i] = -1; //means basis is not defined for i
      BasisSet = new bool[n];
      length1 = n;//on stage 2 n could change but not the length1 since we are not recalculating the matrix
    }

    internal void SetSolution(double[] solution) { x = solution; }
    internal void UpdateBasis(int[] basisParam) { this.basis = basisParam; }
    internal void SetNumberOfVariables(int number) { this.n = number; }
  }
}
