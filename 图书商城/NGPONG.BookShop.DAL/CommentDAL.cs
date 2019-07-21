using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NGPONG.BookShop.Common.Helper;
using NGPONG.BookShop.Model;

namespace NGPONG.BookShop.DAL
{
    public class CommentDAL
    {
        public string AddComment(BookComment bookComment, bool isMod)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@Msg",bookComment.Msg),
                new SqlParameter("@BookId",bookComment.BookId),
                new SqlParameter("@UserId",bookComment.UserId),
                new SqlParameter("@CreateDateTime",bookComment.CreateDateTime),
                new SqlParameter("@IsPass",!isMod)
            };

            return SqlHelper.ExecuteScalar("insert into BookComment(Msg,CreateDateTime,BookId,IsPass,UserId) values(@Msg,@CreateDateTime,@BookId,@IsPass,@UserId);select id from BookComment where Msg = @Msg and BookId = @BookId and UserId = @UserId", parms)?.ToString() ?? string.Empty;
        }

        public void AddReceiveComment(BookCommentReceive bookCommentReceive, bool isMod)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@Msg",bookCommentReceive.Msg),
                new SqlParameter("@CommentId",bookCommentReceive.CommentId),
                new SqlParameter("@UserId",bookCommentReceive.UserId),
                new SqlParameter("@IsPass",!isMod),
                new SqlParameter("@CreateDateTime",bookCommentReceive.CreateDateTime)
            };

            SqlHelper.ExecuteScalar("insert into BookCommentReceive(Msg,CreateDateTime,CommentId,IsPass,UserId) values(@Msg,@CreateDateTime,@CommentId,@IsPass,@UserId)", parms);
        }

        public List<BookComment> GetBookComments(string bookId)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@BookId",bookId)
            };

            // 获取回复信息
            List<BookComment> bookComments = SqlHelper.GetDataList<BookComment>("select a.Id,a.Msg,a.CreateDateTime,a.BookId,a.IsPass,a.UserId,b.Name as UserName from BookComment a left join Users b on a.UserId = b.LoginId where BookId = @BookId and IsPass = '1'", parms);
            string ids = string.Empty;
            for (int i = 0; i < bookComments.Count; i++)
            {
                ids += $"'{bookComments[i].Id}',";
            }

            // 获取指定CommentID的回复信息
            if (!string.IsNullOrEmpty(ids))
            {
                List<BookCommentReceive> commentReceives = GetBookCommentReceives(ids.Substring(0, ids.Length - 1));

                // 数据分组
                var commentReceives_CommentIdGroup = commentReceives.GroupBy(x => x.CommentId);
                foreach (var item in commentReceives_CommentIdGroup)
                {
                    BookComment bookComment = bookComments.Find(x => x.Id == item.Key);
                    bookComment.CommentReceives = item.ToList<BookCommentReceive>();
                }
            }

            return bookComments;
        }

        public List<BookCommentReceive> GetBookCommentReceives(string commentId)
        {
            return SqlHelper.GetDataList<BookCommentReceive>($"select a.Id,a.Msg,a.CreateDateTime,a.IsPass,a.CommentId,a.UserId,b.Name as UserName from BookCommentReceive a left join Users b on a.UserId = b.LoginId where a.CommentId in ({commentId}) and a.IsPass = '1'");
        }
    }
}
