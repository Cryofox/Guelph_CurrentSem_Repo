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

// Copyright (c) 2010 Microsoft Research
//
// The definition of a Property page that is displayed inside
// C# and VB project property pages. It loads and saves
// two properties from/to the project files:
//  AssemblyInfoEnabled: should our assembly info program run?
//  AssemblyInfoFormatString: a format string that is passed as a parameter too.
//
// Using seperate MSBuild integration, these properties are visible
// in a MSBuild targets file. (see the Targets directory)

using System;
using System.Runtime.InteropServices;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;
using Microsoft.VisualStudio.CodeTools;

/*
 * The registry should contain a COM registration of this class:
 * 		HKCR\
 *    CLSID\
 *      {classid}\
 *        (default)  = AssemblyInfo.PropertyPane 
 *        InprocServer32\
 *          (default)     =mscoree.dll
 *          Assembly      =PropertyPane, Version=1.0.0.0, Culture=neutral
 *          Class         =AssemblyInfo.PropertyPane
 *          CodeBase      =c:/.../Samples/AssemblyInfo/PropertyPane/bin/Debug/PropertyPane.dll
 *          ThreadingModel=Both
 *        ProgId\
 *          (default)      =AssemblyInfo.PropertyPane
 *        Implemented Categories\
 *          {62C8FE65-4EBB-45e7-B440-6E39B2CDBF29}
 * 
 * And also a CodeTools registration:
 * 
 * HKLM\Software\Microsoft\VisualStudio\10.0\CodeTools
 *  \AssemblyInfo
 *     \PropertyPages
 *        \{pageid}
 *            clsid = {classid} 
 *            category = ConfigPropertyPages
 *            \Projects
 *               CSharp = ""
 *               
 * where 
 *   {pageid}  = {EAA2FC39-92C8-4e9b-9E3E-4A52D08D1D83} 
 *   {classid} = {DAA2FC39-92C8-4e9b-9E3E-4A52D08D1D83} 
 * The pageid uniquely identifies this property page, while
 * the class id is the 'clsid' of this user control.
 * 
 * After setting all these entries, run the CodeToolsUpdate program
 * to register the property page in VS.
 */
namespace AssemblyInfo
{
	[Guid("DAA2FC39-92C8-4e9b-9E3E-4A52D08D1D83")]
	public partial class PropertyPane : UserControl, IPropertyPane
	{
		#region Fields and constructor
		private ProjectProperty[] properties;

		public PropertyPane()
		{
			InitializeComponent();
			// The names of the properties correspond to the properties defined in the Targets file
			properties = new ProjectProperty[] {
				new CheckBoxProperty( "AssemblyInfoEnabled", EnableCheckBox, false ),
				new TextBoxProperty( "AssemblyInfoFormatString", FormatTextBox, "Assembly: {0}, Version: {1}, Types: {2}")
			};
		}

		private void PropertiesChanged()
		{
			if (host != null) {
				host.PropertiesChanged();
			}
		}

		private void EnableDisableUI()
		{
			FormatTextBox.Enabled = EnableCheckBox.Checked;
		}
		#endregion

		#region IPropertyPane
		private IPropertyPaneHost host; // = null;

		public void SetHost(IPropertyPaneHost h)
		{
			host = h;
		}

		public string Title
		{
			get { return "Assembly Info"; }
		}

		public int HelpContext
		{
			get { return 0; }
		}

		public string HelpFile
		{
			get { return ""; }
		}
		
		public void LoadProperties(string[] configNames, IPropertyStorage storage)
		{
			foreach (var prop in this.properties) {
				prop.Load(configNames, storage);
			}
			EnableDisableUI();
		}

		public void SaveProperties(string[] configNames, IPropertyStorage storage)
		{
			foreach (var prop in this.properties) {
				prop.Save(configNames, storage);
			}
		}
		#endregion

		#region Events
		private void EnableCheckBox_CheckedChanged(object sender, EventArgs e)
		{
			PropertiesChanged();
			EnableDisableUI();
		}

		private void FormatTextBox_TextChanged(object sender, EventArgs e)
		{
			PropertiesChanged();
		}
		#endregion
	}
}
