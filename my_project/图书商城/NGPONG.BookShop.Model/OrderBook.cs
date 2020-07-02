using System;
namespace BookShop.Model
{
	/// <summary>
	/// 实体类OrderBook 。(属性说明自动提取数据库字段的描述信息)
	/// </summary>
	[Serializable]
	public class OrderBook
	{
		public OrderBook()
		{}
		#region Model
		private int _id;
		private string _orderid;
        private Book _book = new Book();


		private int _quantity;
		private decimal _unitprice;
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
		public string OrderID
		{
			set{ _orderid=value;}
			get{return _orderid;}
		}
        public Book Book
        {
            get { return _book; }
            set { _book = value; }
        }
		/// <summary>
		/// 
		/// </summary>
		public int Quantity
		{
			set{ _quantity=value;}
			get{return _quantity;}
		}
		/// <summary>
		/// 
		/// </summary>
		public decimal UnitPrice
		{
			set{ _unitprice=value;}
			get{return _unitprice;}
		}
		#endregion Model

	}
}

