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

// File System.Windows.Media.Imaging.BitmapDecoder.cs
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


namespace System.Windows.Media.Imaging
{
  abstract public partial class BitmapDecoder : System.Windows.Threading.DispatcherObject
  {
    #region Methods and constructors
    protected BitmapDecoder()
    {
    }

    public static System.Windows.Media.Imaging.BitmapDecoder Create(Stream bitmapStream, BitmapCreateOptions createOptions, BitmapCacheOption cacheOption)
    {
      return default(System.Windows.Media.Imaging.BitmapDecoder);
    }

    public static System.Windows.Media.Imaging.BitmapDecoder Create(Uri bitmapUri, BitmapCreateOptions createOptions, BitmapCacheOption cacheOption)
    {
      return default(System.Windows.Media.Imaging.BitmapDecoder);
    }

    public static System.Windows.Media.Imaging.BitmapDecoder Create(Uri bitmapUri, BitmapCreateOptions createOptions, BitmapCacheOption cacheOption, System.Net.Cache.RequestCachePolicy uriCachePolicy)
    {
      return default(System.Windows.Media.Imaging.BitmapDecoder);
    }

    public virtual new InPlaceBitmapMetadataWriter CreateInPlaceBitmapMetadataWriter()
    {
      return default(InPlaceBitmapMetadataWriter);
    }

    #endregion

    #region Properties and indexers
    public virtual new BitmapCodecInfo CodecInfo
    {
      get
      {
        return default(BitmapCodecInfo);
      }
    }

    public virtual new System.Collections.ObjectModel.ReadOnlyCollection<System.Windows.Media.ColorContext> ColorContexts
    {
      get
      {
        return default(System.Collections.ObjectModel.ReadOnlyCollection<System.Windows.Media.ColorContext>);
      }
    }

    public virtual new System.Collections.ObjectModel.ReadOnlyCollection<BitmapFrame> Frames
    {
      get
      {
        return default(System.Collections.ObjectModel.ReadOnlyCollection<BitmapFrame>);
      }
    }

    public virtual new bool IsDownloading
    {
      get
      {
        return default(bool);
      }
    }

    public virtual new BitmapMetadata Metadata
    {
      get
      {
        return default(BitmapMetadata);
      }
    }

    public virtual new BitmapPalette Palette
    {
      get
      {
        return default(BitmapPalette);
      }
    }

    public virtual new BitmapSource Preview
    {
      get
      {
        return default(BitmapSource);
      }
    }

    public virtual new BitmapSource Thumbnail
    {
      get
      {
        return default(BitmapSource);
      }
    }
    #endregion

    #region Events
    public virtual new event EventHandler DownloadCompleted
    {
      add
      {
      }
      remove
      {
      }
    }

    public virtual new event EventHandler<System.Windows.Media.ExceptionEventArgs> DownloadFailed
    {
      add
      {
      }
      remove
      {
      }
    }

    public virtual new event EventHandler<DownloadProgressEventArgs> DownloadProgress
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
