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

// File System.Configuration.ConfigurationElement.cs
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
  abstract public partial class ConfigurationElement
  {
    #region Methods and constructors
    protected ConfigurationElement()
    {
    }

    protected internal virtual new void DeserializeElement(System.Xml.XmlReader reader, bool serializeCollectionKey)
    {
    }

    public override bool Equals(Object compareTo)
    {
      return default(bool);
    }

    public override int GetHashCode()
    {
      return default(int);
    }

    protected virtual new string GetTransformedAssemblyString(string assemblyName)
    {
      return default(string);
    }

    protected virtual new string GetTransformedTypeString(string typeName)
    {
      return default(string);
    }

    protected internal virtual new void Init()
    {
    }

    protected internal virtual new void InitializeDefault()
    {
    }

    protected internal virtual new bool IsModified()
    {
      return default(bool);
    }

    public virtual new bool IsReadOnly()
    {
      return default(bool);
    }

    protected virtual new void ListErrors(System.Collections.IList errorList)
    {
    }

    protected virtual new bool OnDeserializeUnrecognizedAttribute(string name, string value)
    {
      return default(bool);
    }

    protected virtual new bool OnDeserializeUnrecognizedElement(string elementName, System.Xml.XmlReader reader)
    {
      return default(bool);
    }

    protected virtual new Object OnRequiredPropertyNotFound(string name)
    {
      return default(Object);
    }

    protected virtual new void PostDeserialize()
    {
    }

    protected virtual new void PreSerialize(System.Xml.XmlWriter writer)
    {
    }

    protected internal virtual new void Reset(System.Configuration.ConfigurationElement parentElement)
    {
    }

    protected internal virtual new void ResetModified()
    {
    }

    protected internal virtual new bool SerializeElement(System.Xml.XmlWriter writer, bool serializeCollectionKey)
    {
      return default(bool);
    }

    protected internal virtual new bool SerializeToXmlElement(System.Xml.XmlWriter writer, string elementName)
    {
      return default(bool);
    }

    protected void SetPropertyValue(ConfigurationProperty prop, Object value, bool ignoreLocks)
    {
    }

    protected internal virtual new void SetReadOnly()
    {
    }

    protected internal virtual new void Unmerge(System.Configuration.ConfigurationElement sourceElement, System.Configuration.ConfigurationElement parentElement, ConfigurationSaveMode saveMode)
    {
    }
    #endregion

    #region Properties and indexers
    public Configuration CurrentConfiguration
    {
      get
      {
        return default(Configuration);
      }
    }

    public ElementInformation ElementInformation
    {
      get
      {
        return default(ElementInformation);
      }
    }

    internal protected virtual new ConfigurationElementProperty ElementProperty
    {
      get
      {
        return default(ConfigurationElementProperty);
      }
    }

    protected ContextInformation EvaluationContext
    {
      get
      {
        return default(ContextInformation);
      }
    }

    internal protected Object this [ConfigurationProperty prop]
    {
      get
      {
        return default(Object);
      }
      set
      {
      }
    }

    internal protected Object this [string propertyName]
    {
      get
      {
        Contract.Requires(this.Properties != null);

        return default(Object);
      }
      set
      {
        Contract.Requires(this.Properties != null);
      }
    }

    public ConfigurationLockCollection LockAllAttributesExcept
    {
      get
      {
        return default(ConfigurationLockCollection);
      }
    }

    public ConfigurationLockCollection LockAllElementsExcept
    {
      get
      {
        return default(ConfigurationLockCollection);
      }
    }

    public ConfigurationLockCollection LockAttributes
    {
      get
      {
        return default(ConfigurationLockCollection);
      }
    }

    public ConfigurationLockCollection LockElements
    {
      get
      {
        return default(ConfigurationLockCollection);
      }
    }

    public bool LockItem
    {
      get
      {
        return default(bool);
      }
      set
      {
      }
    }

    internal protected virtual new ConfigurationPropertyCollection Properties
    {
      get
      {
        return default(ConfigurationPropertyCollection);
      }
    }
    #endregion
  }
}
