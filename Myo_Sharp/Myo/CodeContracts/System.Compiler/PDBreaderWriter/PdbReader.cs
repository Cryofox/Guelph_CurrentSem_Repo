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

#if UseSingularityPDB

///////////////////////////////////////////////////////////////////////////////
//
//  Microsoft Research Singularity PDB Info Library
//
//  Copyright (c) Microsoft Corporation.  All rights reserved.
//
//  File:   PdbReader.cs
//
using System;
using System.IO;

namespace Microsoft.Singularity.PdbInfo.Features
{
    public class PdbReader
    {
        public PdbReader(Stream reader, int pageSize)
        {
            this.pageSize = pageSize;
            this.reader = reader;
        }

        public void Seek(int page, int offset)
        {
            reader.Seek(page * pageSize + offset, SeekOrigin.Begin);
        }

        public void Read(byte[] bytes, int offset, int count)
        {
            reader.Read(bytes, offset, count);
        }

        public int PagesFromSize(int size)
        {
            return (size + pageSize - 1) / (pageSize);
        }

        public int PageSize
        {
            get { return pageSize; }
        }

        internal readonly int pageSize;
        internal readonly Stream reader;
    }
}
#endif