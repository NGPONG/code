using NGPONG.BookShop.DAL;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.BLL
{
    public class CommentService
    {
        public string AddComment(BookComment bookComment, bool isMod)
        {
            return new CommentDAL().AddComment(bookComment, isMod);
        }
        public void AddReceiveComment(BookCommentReceive bookCommentReceive, bool isMod)
        {
            new CommentDAL().AddReceiveComment(bookCommentReceive, isMod);
        }

        public List<BookComment> GetBookComments(string bookId)
        {
            return new CommentDAL().GetBookComments(bookId);
        }
    }
}
