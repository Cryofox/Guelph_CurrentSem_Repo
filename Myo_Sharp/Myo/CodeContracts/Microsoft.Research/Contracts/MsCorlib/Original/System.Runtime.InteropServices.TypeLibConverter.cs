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

namespace System.Runtime.InteropServices
{

    public class TypeLibConverter
    {

        public TypeLibConverter () {

          return default(TypeLibConverter);
        }
        public bool GetPrimaryInteropAssembly (Guid g, int major, int minor, int lcid, ref string asmName, ref string asmCodeBase) {

          return default(bool);
        }
        public object ConvertAssemblyToTypeLib (System.Reflection.Assembly assembly, string strTypeLibName, TypeLibExporterFlags flags, ITypeLibExporterNotifySink notifySink) {

          return default(object);
        }
        public System.Reflection.Emit.AssemblyBuilder ConvertTypeLibToAssembly (object! typeLib, string! asmFileName, TypeLibImporterFlags flags, ITypeLibImporterNotifySink! notifySink, Byte[]! publicKey, System.Reflection.StrongNameKeyPair! keyPair, string asmNamespace, Version asmVersion) {
            CodeContract.Requires(typeLib != null);
            CodeContract.Requires(asmFileName != null);
            CodeContract.Requires(notifySink != null);
            CodeContract.Requires(asmFileName.Length <= 260);
          return default(System.Reflection.Emit.AssemblyBuilder);
        }
            CodeContract.Requires((int)((int)flags & 1) == 0 || publicKey != null || keyPair != null) {

                                                                  return default(ey);
                                                                }
          return default(System.Reflection.Emit.AssemblyBuilder);
        }
        public System.Reflection.Emit.AssemblyBuilder ConvertTypeLibToAssembly (object typeLib, string asmFileName, int flags, ITypeLibImporterNotifySink notifySink, Byte[] publicKey, System.Reflection.StrongNameKeyPair keyPair, bool unsafeInterfaces) {
    }
}
