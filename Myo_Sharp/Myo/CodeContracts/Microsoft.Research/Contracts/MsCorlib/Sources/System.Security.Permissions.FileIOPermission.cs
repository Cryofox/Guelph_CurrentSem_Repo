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

// File System.Security.Permissions.FileIOPermission.cs
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


namespace System.Security.Permissions
{
  sealed public partial class FileIOPermission : System.Security.CodeAccessPermission, IUnrestrictedPermission, IBuiltInPermission
  {
    #region Methods and constructors
    public void AddPathList(FileIOPermissionAccess access, string[] pathList)
    {
    }

    public void AddPathList(FileIOPermissionAccess access, string path)
    {
    }

    public override System.Security.IPermission Copy()
    {
      return default(System.Security.IPermission);
    }

    public override bool Equals(Object obj)
    {
      return default(bool);
    }

    public FileIOPermission(PermissionState state)
    {
    }

    public FileIOPermission(FileIOPermissionAccess access, string[] pathList)
    {
    }

    public FileIOPermission(FileIOPermissionAccess access, System.Security.AccessControl.AccessControlActions control, string[] pathList)
    {
    }

    public FileIOPermission(FileIOPermissionAccess access, System.Security.AccessControl.AccessControlActions control, string path)
    {
    }

    public FileIOPermission(FileIOPermissionAccess access, string path)
    {
    }

    public override void FromXml(System.Security.SecurityElement esd)
    {
    }

    public override int GetHashCode()
    {
      return default(int);
    }

    public string[] GetPathList(FileIOPermissionAccess access)
    {
      return default(string[]);
    }

    public override System.Security.IPermission Intersect(System.Security.IPermission target)
    {
      return default(System.Security.IPermission);
    }

    public override bool IsSubsetOf(System.Security.IPermission target)
    {
      return default(bool);
    }

    public bool IsUnrestricted()
    {
      return default(bool);
    }

    public void SetPathList(FileIOPermissionAccess access, string path)
    {
    }

    public void SetPathList(FileIOPermissionAccess access, string[] pathList)
    {
    }

    int System.Security.Permissions.IBuiltInPermission.GetTokenIndex()
    {
      return default(int);
    }

    public override System.Security.SecurityElement ToXml()
    {
      return default(System.Security.SecurityElement);
    }

    public override System.Security.IPermission Union(System.Security.IPermission other)
    {
      return default(System.Security.IPermission);
    }
    #endregion

    #region Properties and indexers
    public FileIOPermissionAccess AllFiles
    {
      get
      {
        Contract.Ensures(((System.Security.Permissions.FileIOPermissionAccess)(0)) <= Contract.Result<System.Security.Permissions.FileIOPermissionAccess>());
        Contract.Ensures(Contract.Result<System.Security.Permissions.FileIOPermissionAccess>() <= ((System.Security.Permissions.FileIOPermissionAccess)(15)));

        return default(FileIOPermissionAccess);
      }
      set
      {
      }
    }

    public FileIOPermissionAccess AllLocalFiles
    {
      get
      {
        Contract.Ensures(((System.Security.Permissions.FileIOPermissionAccess)(0)) <= Contract.Result<System.Security.Permissions.FileIOPermissionAccess>());
        Contract.Ensures(Contract.Result<System.Security.Permissions.FileIOPermissionAccess>() <= ((System.Security.Permissions.FileIOPermissionAccess)(15)));

        return default(FileIOPermissionAccess);
      }
      set
      {
      }
    }
    #endregion
  }
}
