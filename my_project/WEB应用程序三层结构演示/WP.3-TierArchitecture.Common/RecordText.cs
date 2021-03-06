﻿using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WP._3_TierArchitecture.Common
{
    public static class RecordText
    {
        /// <summary>
        ///  写日志
        /// </summary>
        /// <param name="time">执行时间</param>
        /// <param name="methodName">函数名称</param>
        /// <param name="sql">SQL语句</param>
        /// <param name="parms">参数</param>
        /// <param name="errMessage">错误信息</param>
        public static void Write(double time, string methodName, string sql, SqlParameter[] parms, string errMessage)
        {
            // 如果不存在则创建文件夹
            if (!Directory.Exists(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "log")))
            {
                Directory.CreateDirectory(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "log"));
            }

            string speedLevel;
            #region 获取速度等级
            if (time > 0.0001 && time < 0.001)
            {
                speedLevel = "A";
            }
            else if (time > 0.001 && time < 0.01)
            {
                speedLevel = "B";
            }
            else if (time > 0.01 && time < 1)
            {
                speedLevel = "C";
            }
            else if (time > 1 && time < 5)
            {
                speedLevel = "D";
            }
            else
            {
                speedLevel = "F";
            }
            #endregion

            string parmsContent;
            #region 获取参数值
            if (parms == null)
            {
                parmsContent = string.Empty;
            }
            else
            {
                List<string> listTemp = new List<string>();
                for (int i = 0; i < parms.Length; i++)
                {
                    string strTemp = parms[i].ParameterName + "#" + parms[i].Value.ToString();
                    listTemp.Add(strTemp);
                }
                parmsContent = string.Join(" | ", listTemp.ToArray());
            }
            #endregion

            string filePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "log") + "\\" + DateTime.Now.ToLongDateString() + DateTime.Now.Hour.ToString() + "点.txt";

            using (StreamWriter writer = new StreamWriter(filePath, true, Encoding.UTF8))
            {
                writer.Write("函数名称：" + methodName + "\r\n");
                writer.Write("调用日期：" + DateTime.Now.ToString() + "\r\n");
                writer.Write("所需时间：" + time + "\r\n");
                writer.Write("速度等级：" + speedLevel + "\r\n");
                writer.Write("SQL脚本：" + sql + "\r\n");
                writer.Write("参数值：" + parmsContent + "\r\n");
                writer.Write("错误信息：" + errMessage + "\r\n\r\n");
            }
        }
    }

}
