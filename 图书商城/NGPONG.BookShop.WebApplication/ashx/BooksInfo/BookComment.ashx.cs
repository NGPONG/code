using NGPONG.BookShop.BLL;
using NGPONG.BookShop.Common.Unitis;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Script.Serialization;
using System.Web.SessionState;

namespace NGPONG.BookShop.WebApplication.ashx.BooksInfo
{
    public class BookComment : IHttpHandler, IRequiresSessionState
    {
        JavaScriptSerializer jsonSerializer = new JavaScriptSerializer();
        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            if (context.Request.Form["Action"] == "Select")
            {
                LoadComment(context);
            }
            else
            {
                // 检查用户在线状态
                CheckUserLogin(context);

                string msg = new Articel_WordsService().CheckReplace(context.Server.HtmlEncode(context.Request["txtContent"]));

                bool isMod;
                CheckWords(context, msg, out isMod);
                if (context.Request.Form["Action"] == "Add")
                {
                    AddComment(context, msg, isMod);
                }
                else if (context.Request.Form["Action"] == "Receive")
                {
                    ReceiveComment(context, msg, isMod);
                }
                else
                {
                    context.Response.Write(jsonSerializer.Serialize(new
                    {
                        IsSuccess = false,
                        Message = "远程调用行为不匹配!",
                        Status = "500"
                    }));

                    context.Response.End();
                }
            }
        }
        private void CheckUserLogin(HttpContext context)
        {
            // 判断用户是否离线
            if (context.Session["UserInfo"] == null)
            {
                context.Response.Write(jsonSerializer.Serialize(new
                {
                    IsSuccess = false,
                    Message = (context.Request.Cookies["cp1"] != null && context.Request.Cookies["cp2"] != null) ? string.Empty : "用户名已过期，请重新登录",
                    Status = "302",
                    RedirectUrl = $"/Member/Login.aspx?RedirectUrl={context.Request.UrlReferrer.ToString()}"
                }));

                context.Response.End();
            }
        }
        private void LoadComment(HttpContext context)
        {
            string bookId = context.Request["BookId"];

            // 获取指定BookId的数据
            CommentService commentService = new CommentService();
            List<Model.BookComment> bookComments = commentService.GetBookComments(bookId);

            // 修改日期
            for (int i = 0; i < bookComments.Count; i++)
            {
                bookComments[i].CreateDateTime = WebCommon.ConvertCommentCreateDate(Convert.ToDateTime(bookComments[i].CreateDateTime));
                bookComments[i].Msg = context.Server.HtmlEncode(bookComments[i].Msg);
                if (bookComments[i].CommentReceives != null)
                {
                    for (int j = 0; j < bookComments[i].CommentReceives.Count; j++)
                    {
                        bookComments[i].CommentReceives[j].CreateDateTime = WebCommon.ConvertCommentCreateDate(Convert.ToDateTime(bookComments[i].CommentReceives[j].CreateDateTime));
                        bookComments[i].CommentReceives[j].Msg = context.Server.HtmlEncode(bookComments[i].CommentReceives[j].Msg);
                    }
                }
            }

            // 返回
            context.Response.Write(jsonSerializer.Serialize(new
            {
                IsSuccess = true,
                Message = "Success",
                Info = bookComments
            }));
        }

        public void AddComment(HttpContext context, string msg, bool isMod)
        {
            var userInfo = context.Session["UserInfo"] as Model.Users;

            var bookComment = new Model.BookComment()
            {
                BookId = context.Request["BookId"],
                Msg = msg,
                UserId = userInfo.LoginId,
                CreateDateTime = DateTime.Now.ToString()
            };

            // 添加信息
            CommentService commentService = new CommentService();
            string id = commentService.AddComment(bookComment, isMod);

            // 修改信息
            bookComment.CreateDateTime = WebCommon.ConvertCommentCreateDate(Convert.ToDateTime(bookComment.CreateDateTime));
            bookComment.UserName = userInfo.Name;
            bookComment.Id = id;

            if (isMod)
            {
                context.Response.Write(jsonSerializer.Serialize(new
                {
                    IsSuccess = false,
                    Message = "发表评论成功!但是存在审核词汇，审核通过后就他妈给你显示出来",
                    Status = "501"
                }));
            }
            else
            {
                context.Response.Write(jsonSerializer.Serialize(new
                {
                    IsSuccess = true,
                    Message = "发表评论成功!",
                    Info = new List<Model.BookComment>()
                    {
                        bookComment
                    }
                }));
            }
        }
        public void ReceiveComment(HttpContext context, string msg, bool isMod)
        {
            var userInfo = context.Session["UserInfo"] as Model.Users;

            var bookCommentReceive = new Model.BookCommentReceive()
            {
                CommentId = context.Request["CommentId"].Replace("'", string.Empty),
                Msg = msg,
                UserId = userInfo.LoginId,
                CreateDateTime = DateTime.Now.ToString()
            };

            // 添加信息
            CommentService commentService = new CommentService();
            commentService.AddReceiveComment(bookCommentReceive, isMod);

            // 修改信息
            bookCommentReceive.CreateDateTime = WebCommon.ConvertCommentCreateDate(Convert.ToDateTime(bookCommentReceive.CreateDateTime));
            bookCommentReceive.UserName = userInfo.Name;

            if (isMod)
            {
                context.Response.Write(jsonSerializer.Serialize(new
                {
                    IsSuccess = false,
                    Message = "发表评论成功!但是存在审核词汇，审核通过后就他妈给你显示出来",
                    Status = "501"
                }));
            }
            else
            {
                context.Response.Write(jsonSerializer.Serialize(new
                {
                    IsSuccess = true,
                    Message = "发表评论成功!",
                    Info = new List<Model.BookCommentReceive>()
                    {
                        bookCommentReceive
                    }
                }));
            }
        }
        public void CheckWords(HttpContext context, string msg, out bool flag)
        {
            flag = false;

            Articel_WordsService articel_WordsService = new Articel_WordsService();
            if (articel_WordsService.CheckForbidMsg(msg))
            {
                context.Response.Write(jsonSerializer.Serialize(new
                {
                    IsSuccess = false,
                    Message = "评论发表失败!当前评论含有敏感词汇",
                    Status = "501"
                }));

                context.Response.End();
            }
            else if (articel_WordsService.CheckModMsg(msg))
            {
                flag = true;
            }
        }

        public bool IsReusable
        {
            get
            {
                return false;
            }
        }
    }
}