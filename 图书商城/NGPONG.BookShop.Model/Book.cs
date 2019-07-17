using System;
namespace BookShop.Model
{
	/// <summary>
	/// ʵ����Books ��(����˵���Զ���ȡ���ݿ��ֶε�������Ϣ)
	/// </summary>
	[Serializable]
	public class Book
	{
        public string Id { get; set; }
        public string Title { get; set; }
        public string Author { get; set; }
        public string Publisher { get; set; }
        public string PublisherId { get; set; }
        public string PublishDate { get; set; }
        public string ISBN { get; set; }
        public string WordsCount { get; set; }
        public string UnitPrice { get; set; }
        public string ContentDescription { get; set; }
        public string AurhorDescription { get; set; }
        public string EditorComment { get; set; }
        public string TOC { get; set; }
        public string Category { get; set; }
        public string Clicks { get; set; }
        public string PageSize { get; set; }
    }
}

