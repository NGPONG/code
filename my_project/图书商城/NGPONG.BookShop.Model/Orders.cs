using NGPONG.BookShop.Model;
using System;
namespace BookShop.Model
{
	/// <summary>
	/// 实体类Orders 。(属性说明自动提取数据库字段的描述信息)
	/// </summary>
	[Serializable]
	public class Orders
	{
		public Orders()
		{}
		#region Model
		private string _orderId;
		private DateTime _orderdate;
        private Users _user = new Users();
        private int _state;
        private string _postAddress;

        public string PostAddress
        {
            get { return _postAddress; }
            set { _postAddress = value; }
        }

        public int State
        {
            get { return _state; }
            set { _state = value; }
        }

        public Users User
        {
            get { return _user; }
            set { _user = value; }
        }
		private decimal _totalprice;
		/// <summary>
		/// 
		/// </summary>
		public string OrderId
		{
            set { _orderId = value; }
            get { return _orderId; }
		}
		/// <summary>
		/// 
		/// </summary>
		public DateTime OrderDate
		{
			set{ _orderdate=value;}
			get{return _orderdate;}
		}
	
		/// <summary>
		/// 
		/// </summary>
		public decimal TotalPrice
		{
			set{ _totalprice=value;}
			get{return _totalprice;}
		}
		#endregion Model

	}
}

