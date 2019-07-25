using NGPONG.BookShop.Model;
using System;
namespace BookShop.Model
{
    public class Cart
    {
        public string Id { get; set; }
        public string UserId { get; set; }
        public string BookId { get; set; }
        public string Count { get; set; }
        public string CreateDate { get; set; }
    }
}

