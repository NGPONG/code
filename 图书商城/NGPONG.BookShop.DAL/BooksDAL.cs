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
        public List<Book> GetBooksList(int currentPage)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@CurrentPage",currentPage)
            };

            StringBuilder sql = new StringBuilder();
            sql.AppendLine("select Temp.* from");
            sql.AppendLine("(select cast(count(1) over() / 7.0 as decimal) as PageSize,ROW_NUMBER() over(order by Id) as num,* from Books) as Temp");
            sql.AppendLine("where Temp.num between ((@CurrentPage-1) * 7 +1) and (7 * @CurrentPage)");

            return SqlHelper.GetDataList<Book>(sql.ToString(), parms);
        }

        public List<Book> GetAllBooksList()
        {
            return SqlHelper.GetDataList<Book>("select * from books");
        }
    }
}
