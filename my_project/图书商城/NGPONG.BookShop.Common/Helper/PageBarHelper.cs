using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;

namespace NGPONG.BookShop.Common.Helper
{
    public static class PageBarHelper
    {
        public static string GetPageBar(int CurrentPage,int PageSize)
        {
            StringBuilder pageStr = new StringBuilder();
            HttpContext context = HttpContext.Current;
            pageStr.AppendLine("<div class=\"numPages\">");
            pageStr.AppendLine("    <table>");
            pageStr.AppendLine("        <tr>");

            if (CurrentPage <= 5)
            {
                for (int i = 0; i < 7; i++)
                {
                    int temp = i + 1;
                    if (temp == CurrentPage)
                    {
                        pageStr.AppendLine("<td style=\"color: red\">" + CurrentPage.ToString() + "</td>");
                        continue;
                    }

                    pageStr.AppendLine("<td><a href = \"/Member/BookList_"+ temp.ToString() + ".aspx\">" + temp.ToString() + "</a></td>");
                }
                pageStr.AppendLine("<td>   ...   </td>" + "<td><a href = \"/Member/BookList_"+ PageSize.ToString() + ".aspx\">" + PageSize.ToString() + "</a></td>");
            }
            else if (CurrentPage >= PageSize - 5)
            {
                pageStr.AppendLine("<td><a href = \"/Member/BookList_1.aspx\">1</a></td><td>   ...   </td>");
                for (int i = PageSize - 7; i <= PageSize; i++)
                {
                    if (i == CurrentPage)
                    {
                        pageStr.AppendLine("<td style=\"color: red\">" + CurrentPage.ToString() + "</td>");
                    }
                    else
                    {
                        pageStr.AppendLine("<td><a href = \"/Member/BookList_"+ i.ToString() + ".aspx\">" + i.ToString() + "</a></td>");
                    }
                }

            }
            else
            {
                pageStr.AppendLine("<td><a href = \"/Member/BookList_1.aspx\">1</a></td><td>   ...   </td>");

                string strTemp = "<td style=\"color: red\">" + CurrentPage.ToString() + "</td>";

                int temp = 0;
                for (int i = CurrentPage; i < CurrentPage + 2; i++)
                {
                    strTemp = "<td><a href = \"/Member/BookList_" + (i - (temp * 2 + 1)).ToString() + ".aspx\">" + (i - (temp * 2 + 1)).ToString() + "</a></td>" + strTemp + "<td><a href = \"/Member/BookList_" + (i + 1).ToString() + ".aspx\">" + (i + 1).ToString() + "</a></td>";
                    temp++;
                }

                strTemp += "<td>   ...   </td><td><a href = \"/Member/BookList_" + PageSize.ToString() + ".aspx\">" + PageSize.ToString() + "</a></td>";

                pageStr.AppendLine(strTemp);
            }

            pageStr.AppendLine("        </tr>");
            pageStr.AppendLine("    </table>");
            pageStr.AppendLine("</div>");

            return pageStr.ToString();
        }
    }
}
