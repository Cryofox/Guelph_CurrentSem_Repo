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

#if !SILVERLIGHT

using System;
using System.Diagnostics;
using System.Diagnostics.Contracts;

namespace Microsoft.VisualBasic.Logging
{
  public class Log
  {
    public Log(string name)
    {
      Contract.Requires(name != null);
    }

    //public void WriteEntry(string message);
    //public void WriteEntry(string message, TraceEventType severity);
    //public void WriteEntry(string message, TraceEventType severity, int id);
    //public void WriteException(Exception ex);
    //public void WriteException(Exception ex, TraceEventType severity, string additionalInfo);
    //public void WriteException(Exception ex, TraceEventType severity, string additionalInfo, int id);

    // Properties
    public FileLogTraceListener DefaultFileLogWriter
    {
      get
      {
        Contract.Ensures(Contract.Result<FileLogTraceListener>() != null);
        return default(FileLogTraceListener);
      }
    }

    public TraceSource TraceSource
    {
      get
      {
        Contract.Ensures(Contract.Result<TraceSource>() != null);
        return default(TraceSource);
      }
    }

  }
}
#endif
