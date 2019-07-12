using System;
namespace BookShop.Model
{
	/// <summary>
	/// 实体类Books 。(属性说明自动提取数据库字段的描述信息)
	/// </summary>
	[Serializable]
	public class Book
	{
		public Book()
		{}
		#region Model
		private int _id;
		private string _title;
		private string _author;
		//private int _publisherid;;
        private Publisher _publisher = new Publisher();


		private DateTime _publishdate;
		private string _isbn;
		private int _wordscount;
		private decimal _unitprice;
		private string _contentdescription;
		private string _aurhordescription;
		private string _editorcomment;
		private string _toc;
//		private int _categoryid;
        private Category _category = new Category();


		private int _clicks;
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
		public string Title
		{
			set{ _title=value;}
			get{return _title;}
		}
		/// <summary>
		/// 
		/// </summary>
		public string Author
		{
			set{ _author=value;}
			get{return _author;}
		}
		/// <summary>
		/// 
		/// </summary>
        /// 
        public Publisher Publisher
        {
            get { return _publisher; }
            set { _publisher = value; }
        }
        //public int PublisherId
        //{
        //    set{ _publisherid=value;}
        //    get{return _publisherid;}
        //}
		/// <summary>
		/// 
		/// </summary>
		public DateTime PublishDate
		{
			set{ _publishdate=value;}
			get{return _publishdate;}
		}
		/// <summary>
		/// 
		/// </summary>
		public string ISBN
		{
			set{ _isbn=value;}
			get{return _isbn;}
		}
		/// <summary>
		/// 
		/// </summary>
		public int WordsCount
		{
			set{ _wordscount=value;}
			get{return _wordscount;}
		}
		/// <summary>
		/// 
		/// </summary>
		public decimal UnitPrice
		{
			set{ _unitprice=value;}
			get{return _unitprice;}
		}
		/// <summary>
		/// 
		/// </summary>
		public string ContentDescription
		{
			set{ _contentdescription=value;}
			get{return _contentdescription;}
		}
		/// <summary>
		/// 
		/// </summary>
		public string AurhorDescription
		{
			set{ _aurhordescription=value;}
			get{return _aurhordescription;}
		}
		/// <summary>
		/// 
		/// </summary>
		public string EditorComment
		{
			set{ _editorcomment=value;}
			get{return _editorcomment;}
		}
		/// <summary>
		/// 
		/// </summary>
		public string TOC
		{
			set{ _toc=value;}
			get{return _toc;}
		}
		/// <summary>
		/// 
		/// </summary>
        public Category Category
        {
            get { return _category; }
            set { _category = value; }
        }
		/// <summary>
		/// 
		/// </summary>
		public int Clicks
		{
			set{ _clicks=value;}
			get{return _clicks;}
		}
		#endregion Model

	}
}

