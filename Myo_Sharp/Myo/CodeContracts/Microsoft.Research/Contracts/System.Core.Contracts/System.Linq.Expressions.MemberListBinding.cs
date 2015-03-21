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
using System.Collections.ObjectModel;
using System.Reflection;
using System.Text;
using System.Diagnostics.Contracts;

namespace System.Linq.Expressions
{
  // Summary:
  //     Represents initializing the elements of a collection member of a newly created
  //     object.
  public sealed class MemberListBinding 
  {
    private MemberListBinding() { }

    // Summary:
    //     Gets the element initializers for initializing a collection member of a newly
    //     created object.
    //
    // Returns:
    //     A System.Collections.ObjectModel.ReadOnlyCollection<T> of System.Linq.Expressions.ElementInit
    //     objects to initialize a collection member with.
    public ReadOnlyCollection<ElementInit> Initializers
    {
      get
      {
        Contract.Ensures(Contract.Result<ReadOnlyCollection<ElementInit>>() != null);
        return default(ReadOnlyCollection<ElementInit>);
      }
    }
  }
}
