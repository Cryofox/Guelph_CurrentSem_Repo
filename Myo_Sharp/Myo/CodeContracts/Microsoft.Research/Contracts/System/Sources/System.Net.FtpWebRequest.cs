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

// File System.Net.FtpWebRequest.cs
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


namespace System.Net
{
  sealed public partial class FtpWebRequest : WebRequest
  {
    #region Methods and constructors
    public override void Abort()
    {
    }

    public override IAsyncResult BeginGetRequestStream(AsyncCallback callback, Object state)
    {
      return default(IAsyncResult);
    }

    public override IAsyncResult BeginGetResponse(AsyncCallback callback, Object state)
    {
      return default(IAsyncResult);
    }

    public override Stream EndGetRequestStream(IAsyncResult asyncResult)
    {
      return default(Stream);
    }

    public override WebResponse EndGetResponse(IAsyncResult asyncResult)
    {
      return default(WebResponse);
    }

    internal FtpWebRequest()
    {
    }

    public override Stream GetRequestStream()
    {
      return default(Stream);
    }

    public override WebResponse GetResponse()
    {
      return default(WebResponse);
    }
    #endregion

    #region Properties and indexers
    public System.Security.Cryptography.X509Certificates.X509CertificateCollection ClientCertificates
    {
      get
      {
        return default(System.Security.Cryptography.X509Certificates.X509CertificateCollection);
      }
      set
      {
      }
    }

    public override string ConnectionGroupName
    {
      get
      {
        return default(string);
      }
      set
      {
      }
    }

    public override long ContentLength
    {
      get
      {
        return default(long);
      }
      set
      {
      }
    }

    public long ContentOffset
    {
      get
      {
        return default(long);
      }
      set
      {
      }
    }

    public override string ContentType
    {
      get
      {
        return default(string);
      }
      set
      {
      }
    }

    public override ICredentials Credentials
    {
      get
      {
        return default(ICredentials);
      }
      set
      {
      }
    }

    public static System.Net.Cache.RequestCachePolicy DefaultCachePolicy
    {
      get
      {
        return default(System.Net.Cache.RequestCachePolicy);
      }
      set
      {
      }
    }

    public bool EnableSsl
    {
      get
      {
        return default(bool);
      }
      set
      {
      }
    }

    public override WebHeaderCollection Headers
    {
      get
      {
        return default(WebHeaderCollection);
      }
      set
      {
      }
    }

    public bool KeepAlive
    {
      get
      {
        return default(bool);
      }
      set
      {
      }
    }

    public override string Method
    {
      get
      {
        return default(string);
      }
      set
      {
      }
    }

    public override bool PreAuthenticate
    {
      get
      {
        return default(bool);
      }
      set
      {
      }
    }

    public override IWebProxy Proxy
    {
      get
      {
        return default(IWebProxy);
      }
      set
      {
      }
    }

    public int ReadWriteTimeout
    {
      get
      {
        return default(int);
      }
      set
      {
      }
    }

    public string RenameTo
    {
      get
      {
        return default(string);
      }
      set
      {
      }
    }

    public override Uri RequestUri
    {
      get
      {
        return default(Uri);
      }
    }

    public ServicePoint ServicePoint
    {
      get
      {
        return default(ServicePoint);
      }
    }

    public override int Timeout
    {
      get
      {
        return default(int);
      }
      set
      {
      }
    }

    public bool UseBinary
    {
      get
      {
        return default(bool);
      }
      set
      {
      }
    }

    public override bool UseDefaultCredentials
    {
      get
      {
        return default(bool);
      }
      set
      {
      }
    }

    public bool UsePassive
    {
      get
      {
        return default(bool);
      }
      set
      {
      }
    }
    #endregion
  }
}
