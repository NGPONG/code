using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace WP.Demo.Common
{
    public static class ConvertWP
    {
        /// <summary>
        ///  返回过过滤空格后的字符串
        /// </summary>
        /// <returns></returns>
        public static string ToTrimString(object obj) 
        {
            try
            {
                string strResult;
                if (obj == null)
                {
                    strResult = string.Empty;
                }
                else 
                {
                    strResult = obj.ToString().Trim();
                }
                return strResult;
            }
            catch (Exception objException) 
            {
                if (objException.InnerException != null) 
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  返回转换后的int类型的数字
        /// </summary>
        /// <param name="convertValue">带转换文本</param>
        /// <param name="defaultValue">默认值文本</param>
        /// <returns></returns>
        public static int ToDeafultInt32(string convertValue, int defaultValue) 
        {
            try
            {
                if (string.IsNullOrEmpty( ConvertWP.ToTrimString(convertValue)))
                {
                    throw new Exception();
                }
                return Convert.ToInt32(convertValue);
            }
            catch 
            {
                return defaultValue;
            }
        }
        /// <summary>
        ///  List转换成DataTable
        /// </summary>
        /// <typeparam name="T">模型类</typeparam>
        /// <param name="listDate">序列化返回后的list集合</param>
        /// <returns>转换后的DataTable</returns>
        public static DataTable ToDataTable<T>(List<T> listDate) 
        {
            try 
            {
                DataTable dtResult = new DataTable();

                if (listDate.Count > 0)
                {
                    List<PropertyInfo[]> list = new List<PropertyInfo[]>(); // 装载着所有行的属性
                    for (int i = 0; i < listDate.Count; i++)
                    {
                        PropertyInfo[] pros = listDate[i].GetType().GetProperties(BindingFlags.Public | BindingFlags.Instance);
                        if (i == 0) // 如果是第一行，则为内存表创建行，取值获取默认第一个类的所有属性，避免做过多的工作
                        {
                            for (int n = 0; n < pros.Length; n++)
                            {
                                dtResult.Columns.Add(pros[n].Name);
                            }
                        }
                        list.Add(pros);
                    }

                    for (int i = 0; i < list.Count; i++)
                    {
                        object[] values = new object[dtResult.Columns.Count]; // 一行

                        for (int n = 0; n < dtResult.Columns.Count; n++)
                        {
                            values[n] = list[i][n].GetValue(listDate[i], null);
                        }

                        dtResult.Rows.Add(values);
                    }
                }

                return dtResult;
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
    }
}
