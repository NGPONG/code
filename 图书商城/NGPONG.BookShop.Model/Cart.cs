using NGPONG.BookShop.Model;
using System;
namespace BookShop.Model
{
	/// <summary>
	/// ʵ����Cart ��(����˵���Զ���ȡ���ݿ��ֶε�������Ϣ)
	/// </summary>
	[Serializable]
	public class Cart
	{
		public Cart()
		{}
		#region Model
		private int _id;
        //private int _userid;
        //private int _bookid;
        private Users _user = new Users();

        private Book _book =  new Book();



		private int _count;

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

        public Users User
        {
            get { return _user; }
            set { _user = value; }
        }
        public Book Book
        {
            get { return _book; }
            set { _book = value; }
        }
		/// <summary>
		/// 
		/// </summary>
		public int Count
		{
			set{ _count=value;}
			get{return _count;}
		}

		#endregion Model

	}
}

