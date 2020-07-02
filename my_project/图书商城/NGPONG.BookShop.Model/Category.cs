using System;
namespace BookShop.Model
{
	/// <summary>
	/// 实体类Categories 。(属性说明自动提取数据库字段的描述信息)
	/// </summary>
	[Serializable]
	public class Category
	{
		public Category()
		{}
		#region Model
		private int _id;
		private string _name;
		/// <summary>
		/// 
		/// </summary>
		public int Id
		{
			set{ _id=value;}
			get{return _id;}
		}
		/// <summary>
		/// 
		/// </summary>
		public string Name
		{
			set{ _name=value;}
			get{return _name;}
		}
		#endregion Model

	}
}

