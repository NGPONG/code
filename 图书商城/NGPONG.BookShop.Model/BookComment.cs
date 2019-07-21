using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.Model
{
    public class BookComment
    {
        public string Id { get; set; }
        public string Msg { get; set; }
        public string CreateDateTime { get; set; }
        public string BookId { get; set; }
        public string IsPass { get; set; }
        public string UserId { get; set; }
        public string UserName { get; set; }
        public List<BookCommentReceive> CommentReceives { get; set; }
    }
}
