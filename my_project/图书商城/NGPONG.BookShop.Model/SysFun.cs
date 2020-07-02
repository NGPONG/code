using System;
namespace BookShop.Model
{
	/// <summary>
	/// SysFun:实体类(属性说明自动提取数据库字段的描述信息)
	/// </summary>
	[Serializable]
	public partial class SysFun
	{
		public SysFun()
		{}
		#region Model
		private int _nodeid;
		private string _displayname;
		private string _nodeurl;
		private int _displayorder;
		private int _parentnodeid;
		/// <summary>
		/// 
		/// </summary>
		public int NodeId
		{
			set{ _nodeid=value;}
			get{return _nodeid;}
		}
		/// <summary>
		/// 
		/// </summary>
		public string DisplayName
		{
			set{ _displayname=value;}
			get{return _displayname;}
		}
		/// <summary>
		/// 
		/// </summary>
		public string NodeURL
		{
			set{ _nodeurl=value;}
			get{return _nodeurl;}
		}
		/// <summary>
		/// 
		/// </summary>
		public int DisplayOrder
		{
			set{ _displayorder=value;}
			get{return _displayorder;}
		}
		/// <summary>
		/// 
		/// </summary>
		public int ParentNodeId
		{
			set{ _parentnodeid=value;}
			get{return _parentnodeid;}
		}
		#endregion Model

	}
}

