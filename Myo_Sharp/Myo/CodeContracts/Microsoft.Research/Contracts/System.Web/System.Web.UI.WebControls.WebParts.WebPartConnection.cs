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

// File System.Web.UI.WebControls.WebParts.WebPartConnection.cs
// Automatically generated contract file.
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Diagnostics.Contracts;
using System;

// Disable the "this variable is not used" warning as every field would imply it.
#pragma warning disable 0414
// Disable the "this variable is never assigned to".
#pragma warning disable 0649
// Disable the "this variable is never used".
#pragma warning disable 0169
// Disable the "new keyword not required" warning.
#pragma warning disable 0109
// Disable the "extern without DllImport" warning.
#pragma warning disable 0626
// Disable the "could hide other member" warning, can happen on certain properties.
#pragma warning disable 0108


namespace System.Web.UI.WebControls.WebParts
{
  sealed public partial class WebPartConnection
  {
    #region Methods and constructors
    public override string ToString ()
    {
      return default(string);
    }

    public WebPartConnection ()
    {
    }
    #endregion

    #region Properties and indexers
    public WebPart Consumer
    {
      get
      {
        Contract.Requires (this.ConsumerID != null);
        Contract.Ensures (this.ConsumerID.Length >= 1);

        return default(WebPart);
      }
    }

    public ConsumerConnectionPoint ConsumerConnectionPoint
    {
      get
      {
        return default(ConsumerConnectionPoint);
      }
    }

    public string ConsumerConnectionPointID
    {
      get
      {
        return default(string);
      }
      set
      {
      }
    }

    public string ConsumerID
    {
      get
      {
        return default(string);
      }
      set
      {
      }
    }

    public string ID
    {
      get
      {
        return default(string);
      }
      set
      {
      }
    }

    public bool IsActive
    {
      get
      {
        return default(bool);
      }
    }

    public bool IsShared
    {
      get
      {
        return default(bool);
      }
    }

    public bool IsStatic
    {
      get
      {
        return default(bool);
      }
    }

    public WebPart Provider
    {
      get
      {
        Contract.Requires (this.ProviderID != null);
        Contract.Ensures (this.ProviderID.Length >= 1);

        return default(WebPart);
      }
    }

    public ProviderConnectionPoint ProviderConnectionPoint
    {
      get
      {
        return default(ProviderConnectionPoint);
      }
    }

    public string ProviderConnectionPointID
    {
      get
      {
        return default(string);
      }
      set
      {
      }
    }

    public string ProviderID
    {
      get
      {
        return default(string);
      }
      set
      {
      }
    }

    public WebPartTransformer Transformer
    {
      get
      {
        return default(WebPartTransformer);
      }
    }

    public WebPartTransformerCollection Transformers
    {
      get
      {
        Contract.Ensures (Contract.Result<System.Web.UI.WebControls.WebParts.WebPartTransformerCollection>() != null);

        return default(WebPartTransformerCollection);
      }
    }
    #endregion
  }
}
