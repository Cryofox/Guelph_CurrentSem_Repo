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

using System.Diagnostics.Contracts;
using System;

namespace System.Security.Cryptography
{

    public class PasswordDeriveBytes
    {

        public int IterationCount
        {
          get;
          set;
        }

        public string HashName
        {
          get;
          set;
        }

        public Byte[] Salt
        {
          get;
          set;
        }

        public Byte[] CryptDeriveKey (string algname, string alghashname, int keySize, Byte[]! rgbIV) {
            CodeContract.Requires(keySize >= 0);
            CodeContract.Requires(rgbIV != null);

          return default(Byte[]);
        }
        public void Reset () {

        }
        public Byte[] GetBytes (int cb) {

          return default(Byte[]);
        }
        public PasswordDeriveBytes (string strPassword, Byte[] rgbSalt, string strHashName, int iterations, CspParameters cspParams) {
            CodeContract.Requires(iterations > 0);

          return default(PasswordDeriveBytes);
        }
        public PasswordDeriveBytes (string strPassword, Byte[] rgbSalt, CspParameters cspParams) {

          return default(PasswordDeriveBytes);
        }
        public PasswordDeriveBytes (string strPassword, Byte[] rgbSalt, string strHashName, int iterations) {

          return default(PasswordDeriveBytes);
        }
          return default(PasswordDeriveBytes);
        }
        public PasswordDeriveBytes (string strPassword, Byte[] rgbSalt) {
    }
}
