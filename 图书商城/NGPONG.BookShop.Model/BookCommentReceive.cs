using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.Model
{
    public class BookCommentReceive
    {
        public string Id { get; set; }
        public string Msg { get; set; }
        public string CreateDateTime { get; set; }
        public string CommentId { get; set; }
        public string UserId { get; set; }
        public string UserName { get; set; }
        public string IsPass { get; set; }
    }
}
