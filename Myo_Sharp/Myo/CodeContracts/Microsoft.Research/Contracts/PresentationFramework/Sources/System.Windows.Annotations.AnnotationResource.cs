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

// File System.Windows.Annotations.AnnotationResource.cs
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


namespace System.Windows.Annotations
{
  sealed public partial class AnnotationResource : System.Xml.Serialization.IXmlSerializable, MS.Internal.Annotations.INotifyPropertyChanged2, System.ComponentModel.INotifyPropertyChanged, MS.Internal.Annotations.IOwnedObject
  {
    #region Methods and constructors
    public AnnotationResource(Guid id)
    {
    }

    public AnnotationResource(string name)
    {
    }

    public AnnotationResource()
    {
    }

    public System.Xml.Schema.XmlSchema GetSchema()
    {
      return default(System.Xml.Schema.XmlSchema);
    }

    public void ReadXml(System.Xml.XmlReader reader)
    {
    }

    public void WriteXml(System.Xml.XmlWriter writer)
    {
    }
    #endregion

    #region Properties and indexers
    public System.Collections.ObjectModel.Collection<ContentLocatorBase> ContentLocators
    {
      get
      {
        Contract.Ensures(Contract.Result<System.Collections.ObjectModel.Collection<System.Windows.Annotations.ContentLocatorBase>>() != null);

        return default(System.Collections.ObjectModel.Collection<ContentLocatorBase>);
      }
    }

    public System.Collections.ObjectModel.Collection<System.Xml.XmlElement> Contents
    {
      get
      {
        Contract.Ensures(Contract.Result<System.Collections.ObjectModel.Collection<System.Xml.XmlElement>>() != null);

        return default(System.Collections.ObjectModel.Collection<System.Xml.XmlElement>);
      }
    }

    public Guid Id
    {
      get
      {
        return default(Guid);
      }
    }

    bool MS.Internal.Annotations.IOwnedObject.Owned
    {
      get
      {
        return default(bool);
      }
      set
      {
      }
    }

    public string Name
    {
      get
      {
        return default(string);
      }
      set
      {
      }
    }
    #endregion

    #region Events
    event System.ComponentModel.PropertyChangedEventHandler System.ComponentModel.INotifyPropertyChanged.PropertyChanged
    {
      add
      {
      }
      remove
      {
      }
    }
    #endregion
  }
}
