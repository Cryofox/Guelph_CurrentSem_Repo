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
using System.Linq;
using System.Text;
using Microsoft.Cci.Pdb;
using System.Diagnostics;

namespace System.Compiler
{
  internal class PdbInfo
  {
    private unsafe Metadata.Reader reader;
    string sourceServerData;
    Dictionary<uint, PdbTokenLine> tokenToSourceMapping;
    //private uint[] remapTable;
    private Dictionary<uint, PdbFunction> pdbFunctionMap;


    public unsafe PdbInfo(IO.FileStream inputStream, Metadata.Reader reader)
    {
      this.reader = reader;
      this.pdbFunctionMap = PdbFile.LoadFunctionMap(inputStream, out tokenToSourceMapping, out sourceServerData, reader);
      //inputStream.Seek(0L, IO.SeekOrigin.Begin);
      //this.remapTable = PdbFile.LoadRemapTable(inputStream);
    }

#if false
    public Method GetMethodFromPdbToken(uint token)
    {
      // remap if necessary
      if (this.remapTable != null)
      {
        token = 0x06000000 | this.remapTable[token & 0xffffff];
      }
      return reader.GetMemberFromToken((int)token) as Method;
    }
#endif

    public PdbFunction GetMethodInfo(uint token)
    {
      PdbFunction result;
      this.pdbFunctionMap.TryGetValue(token, out result);
      return result;
    }
  }
}
