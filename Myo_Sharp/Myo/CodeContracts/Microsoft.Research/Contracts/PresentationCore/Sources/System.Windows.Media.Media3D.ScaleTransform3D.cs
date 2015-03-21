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

// File System.Windows.Media.Media3D.ScaleTransform3D.cs
// Automatically generated contract file.
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Diagnostics.Contracts;
using System;

// Disable the "this variable is not used" warning as every field would imply it.
#pragma warning disable 0414
// Disable the "this variable is never assigned to".
#pragma warning disable 0067
// Disable the "this event is never assigned to".
#pragma warning disable 0649
// Disable the "this variable is never used".
#pragma warning disable 0169
// Disable the "new keyword not required" warning.
#pragma warning disable 0109
// Disable the "extern without DllImport" warning.
#pragma warning disable 0626
// Disable the "could hide other member" warning, can happen on certain properties.
#pragma warning disable 0108


namespace System.Windows.Media.Media3D
{
  sealed public partial class ScaleTransform3D : AffineTransform3D
  {
    #region Methods and constructors
    public System.Windows.Media.Media3D.ScaleTransform3D Clone()
    {
      return default(System.Windows.Media.Media3D.ScaleTransform3D);
    }

    public System.Windows.Media.Media3D.ScaleTransform3D CloneCurrentValue()
    {
      return default(System.Windows.Media.Media3D.ScaleTransform3D);
    }

    protected override System.Windows.Freezable CreateInstanceCore()
    {
      return default(System.Windows.Freezable);
    }

    public ScaleTransform3D()
    {
    }

    public ScaleTransform3D(Vector3D scale, Point3D center)
    {
    }

    public ScaleTransform3D(double scaleX, double scaleY, double scaleZ, double centerX, double centerY, double centerZ)
    {
    }

    public ScaleTransform3D(double scaleX, double scaleY, double scaleZ)
    {
    }

    public ScaleTransform3D(Vector3D scale)
    {
    }
    #endregion

    #region Properties and indexers
    public double CenterX
    {
      get
      {
        return default(double);
      }
      set
      {
      }
    }

    public double CenterY
    {
      get
      {
        return default(double);
      }
      set
      {
      }
    }

    public double CenterZ
    {
      get
      {
        return default(double);
      }
      set
      {
      }
    }

    public double ScaleX
    {
      get
      {
        return default(double);
      }
      set
      {
      }
    }

    public double ScaleY
    {
      get
      {
        return default(double);
      }
      set
      {
      }
    }

    public double ScaleZ
    {
      get
      {
        return default(double);
      }
      set
      {
      }
    }

    public override Matrix3D Value
    {
      get
      {
        return default(Matrix3D);
      }
    }
    #endregion

    #region Fields
    public readonly static System.Windows.DependencyProperty CenterXProperty;
    public readonly static System.Windows.DependencyProperty CenterYProperty;
    public readonly static System.Windows.DependencyProperty CenterZProperty;
    public readonly static System.Windows.DependencyProperty ScaleXProperty;
    public readonly static System.Windows.DependencyProperty ScaleYProperty;
    public readonly static System.Windows.DependencyProperty ScaleZProperty;
    #endregion
  }
}
