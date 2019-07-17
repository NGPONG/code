using BookShop.Model;
using NGPONG.BookShop.Common.Helper;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.DAL
{
    public class BooksDAL
    {
        public List<Book> GetBooksList(PageBar pageBar)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@PageSize",pageBar.PageSize),
                new SqlParameter("@CurrentPage",pageBar.CurrentPage)
            };

            StringBuilder sql = new StringBuilder();
            sql.AppendLine("select Temp.* from");
            sql.AppendLine("(select *,ROW_NUMBER() over(order by Id) as num from Books) as Temp");
            sql.AppendLine("where Temp.num between ((@CurrentPage-1) * @PageSize +1) and (@PageSize*@CurrentPage)");

            return SqlHelper.GetDataList<Book>(sql.ToString(), parms);
        }
    }
}
