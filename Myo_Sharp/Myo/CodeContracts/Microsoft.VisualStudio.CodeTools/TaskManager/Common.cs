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

namespace Microsoft.VisualStudio.CodeTools
{
  using System;
  using System.Collections.Generic;
  using Microsoft.VisualStudio.Shell.Interop;
  using System.Diagnostics;
  using System.ComponentModel;
  using System.Windows.Forms;
  using System.Threading;
	using System.IO;
  
  // Action without arguments
  delegate void Procedure();

  // Common static helper functions
  static internal class Common 
  {
    #region Private fields
    static private IServiceProvider serviceProvider;
    static private IVsSolution solution;
    static private ISynchronizeInvoke syncInvoke;
    #endregion

    #region Construction
    static public void Initialize( IServiceProvider provider )
    {
      serviceProvider = provider;
      solution = GetService( typeof(SVsSolution)) as IVsSolution;

      // we must be called from the main UI thread
      syncInvoke = null;
      Form marshalingForm = new Form();
      if (marshalingForm != null)
      {
        marshalingForm.Visible = false;
        IntPtr handle = marshalingForm.Handle; // forces creation
        syncInvoke = marshalingForm;
      }
      else
      {
        Log("Unable to create a synchronization context for safe thread calls.");
      }
    }

    static public void Release()
    {
      solution = null;
      serviceProvider = null;
    }
    #endregion

    #region Utilities
    [Conditional("TRACE")]
    static public void Trace(string message)
    {
      System.Diagnostics.Debugger.Log(1,"Trace","TaskManager: " + message + "\n");
    }

    static public void Log(string message)
    {
      System.Diagnostics.Debugger.Log(1, "Error", "TaskManager: " + message + "\n");
    }

    static public object GetService( Type serviceType )
    {
      if (serviceProvider != null) 
        return serviceProvider.GetService(serviceType);
      else
        return null;
    }

		static private string VsRoot = null;
    static public String GetLocalRegistryRoot()
    {
      // Get the visual studio root key
			if (VsRoot == null) {
				ILocalRegistry2 localReg = GetService(typeof(ILocalRegistry)) as ILocalRegistry2;
				if (localReg != null) {
					localReg.GetLocalRegistryRoot(out VsRoot);
				}

				if (VsRoot == null) {
					VsRoot = @"Software\Microsoft\VisualStudio\10.0"; // Guess on failure
				}
			}
			return VsRoot;
    }

		static public String GetCodeToolsRegistryRoot()
		{
			return (GetLocalRegistryRoot() + "\\CodeTools");			
		}

    static public void ShowHelp(string helpKeyword)
    {
      if (helpKeyword != null && helpKeyword.Length > 0) {
        IVsHelpSystem help = GetService(typeof(SVsHelpService)) as IVsHelpSystem;
        if (help != null) {
          help.KeywordSearch(helpKeyword, 0, 0);
          help.ActivateHelpSystem(0);
        }
      }
    }
    
    static public void ThreadSafeInvoke(Procedure action)
    {
      if (syncInvoke != null && syncInvoke.InvokeRequired)
      {
        // Common.Trace("Use ISynchronized.Invoke");
        syncInvoke.Invoke(action, null);
      }
      else
      {  
        action();  
      }
    }

    static public void ThreadSafeASync(Procedure action)
    {
      if (syncInvoke != null && syncInvoke.InvokeRequired) {
        // Common.Trace("Use ISynchronized.Invoke");
        syncInvoke.BeginInvoke(action, null);
      }
      else {
        action();
      }
    }

    #endregion

    #region Projects
    static public Guid GetProjectType(IVsHierarchy hierarchy)
    {
      Guid projectType = Guid.Empty;
      if (hierarchy != null) {
        hierarchy.GetGuidProperty(VSConstants.VSITEMID_ROOT, (int)__VSHPROPID.VSHPROPID_TypeGuid, out projectType);
      }
      return projectType;
    }

    static public string GetProjectName(IVsHierarchy hierarchy)
    {
      object name = null;
      if (hierarchy != null) {
        hierarchy.GetProperty(VSConstants.VSITEMID_ROOT, (int)__VSHPROPID.VSHPROPID_Name, out name);
      }
      if (name != null) {
        return name as String;
      }
      else {
        return null;
      }
    }

    static public IVsHierarchy GetProjectByName( string projectName )
    {
      if (projectName != null && projectName.Length > 0 && solution != null) {
        foreach (IVsHierarchy project in GetProjects()) {
          if (String.Compare(projectName,GetProjectName(project),StringComparison.OrdinalIgnoreCase) == 0) {
            return project;
          }
        }
      }
      return null;
    }

    static public IEnumerable<IVsHierarchy> GetProjects()
    {
      if (solution != null) {
        IEnumHierarchies hiers;
        Guid emptyGuid = Guid.Empty;
        int hr = solution.GetProjectEnum((uint)__VSENUMPROJFLAGS.EPF_ALLPROJECTS, ref emptyGuid, out hiers);
        if (hr == 0 && hiers != null) {
          uint fetched;
          do {
            IVsHierarchy[] hier = { null };
            hr = hiers.Next(1, hier, out fetched);
            if (hr == 0 && fetched == 1) {
              yield return (hier[0]);
            }
          }
          while (fetched == 1);
        }
      }
    }

    #endregion
  }
}
