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
using System.Text;
using System.Diagnostics.Contracts;

namespace Tests.Sources
{

#if NETFRAMEWORK_4_5

  using System.Threading.Tasks;

  class NonGen
  {
    public async Task ExecuteBindingAsync(Dictionary<string, bool> actionContext)
    {
      var value = actionContext[""];
      return;
    }

  }

  partial class TestMain
  {
    void TestMe(NonGen g, string[] args, bool mustThrow) {
      var d = new Dictionary<string,bool>();
      foreach (var a in args) { d.Add(a, mustThrow); }
      try {
        var z = g.ExecuteBindingAsync(d);
        if (mustThrow) {
          throw new ArgumentNullException();
        }
      }
      catch (AggregateException ae) {
        if (ae.InnerException is ArgumentException) {
          if (!mustThrow){
            throw;
          }
        }
        else {
          throw;
        }
      }
    }

    void Test()
    {
      var g = new NonGen();
      TestMe(g, new[]{"a", "b"}, false);

      if (!behave) {
        TestMe(g, new[]{"a", "b", "c", "e", "f", "g"}, true);
      }
    }

    partial void Run()
    {
      this.Test();
    }

    public ContractFailureKind NegativeExpectedKind = ContractFailureKind.Precondition;
    public string NegativeExpectedCondition = "Value cannot be null.";
  }
#else
  // Dummy for Pre 4.5
  partial class TestMain 
  {

    void Test() {
      Contract.Requires(false);
    }

    partial void Run()
    {
      if (!behave) {
        this.Test();
      }
    }

    public ContractFailureKind NegativeExpectedKind = ContractFailureKind.Precondition;
    public string NegativeExpectedCondition = "false";
  }
#endif
}
