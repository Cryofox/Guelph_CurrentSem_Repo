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

// File System.Configuration.ConfigurationException.cs
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


namespace System.Configuration
{
  public partial class ConfigurationException : SystemException
  {
    #region Methods and constructors
    public ConfigurationException(string message, Exception inner, System.Xml.XmlNode node)
    {
    }

    public ConfigurationException(string message, string filename, int line)
    {
      Contract.Ensures(0 <= filename.Length);
    }

    public ConfigurationException(string message, Exception inner, string filename, int line)
    {
    }

    public ConfigurationException(string message, System.Xml.XmlNode node)
    {
    }

    public ConfigurationException()
    {
    }

    protected ConfigurationException(System.Runtime.Serialization.SerializationInfo info, System.Runtime.Serialization.StreamingContext context)
    {
      Contract.Requires(info != null);
    }

    public ConfigurationException(string message, Exception inner)
    {
    }

    public ConfigurationException(string message)
    {
    }

    public override void GetObjectData(System.Runtime.Serialization.SerializationInfo info, System.Runtime.Serialization.StreamingContext context)
    {
    }

    public static string GetXmlNodeFilename(System.Xml.XmlNode node)
    {
      return default(string);
    }

    public static int GetXmlNodeLineNumber(System.Xml.XmlNode node)
    {
      return default(int);
    }
    #endregion

    #region Properties and indexers
    public virtual new string BareMessage
    {
      get
      {
        return default(string);
      }
    }

    public virtual new string Filename
    {
      get
      {
        return default(string);
      }
    }

    public virtual new int Line
    {
      get
      {
        return default(int);
      }
    }

    public override string Message
    {
      get
      {
        return default(string);
      }
    }
    #endregion
  }
}
