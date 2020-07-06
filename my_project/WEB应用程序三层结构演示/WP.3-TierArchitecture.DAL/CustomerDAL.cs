using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WP._3_TierArchitecture.Common;

namespace WP._3_TierArchitecture.DAL
{
    public class CustomerDAL
    {
        /// <summary>
        ///  获取数据
        /// </summary>
        /// <returns>查询后的结果内存表</returns>
        public DataTable GetData()
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string sql = "SELECT TOP 10 * FROM SalesLT.Customer order by CustomerID desc";

            try
            {
                DataTable dtResult = SqlHelper.GetDataTable(sql);
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
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, null, errMessage);
            }
        }
        /// <summary>
        ///  添加明细
        /// </summary>
        /// <param name="dicCustomerInfo">参数</param>
        /// <returns>受影响行数</returns>
        public int AddDetail(Dictionary<string, string> dicCustomerInfo) 
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string Gender = dicCustomerInfo["Gender"];
            string FirstName = dicCustomerInfo["FirstName"];
            string MiddleName = dicCustomerInfo["MiddleName"];
            string LastName = dicCustomerInfo["LastName"];
            string CompanyName = dicCustomerInfo["CompanyName"];
            string Phone = dicCustomerInfo["Phone"];
            string MailAddress = dicCustomerInfo["MailAddress"];

            SqlParameter[] parms = new SqlParameter[] { new SqlParameter("@Gender", Gender),
                                                                       new SqlParameter("@FirstName",FirstName),
                                                                       new SqlParameter("@MiddleName",MiddleName),
                                                                       new SqlParameter("@LastName",LastName),
                                                                       new SqlParameter("@CompanyName",CompanyName),
                                                                       new SqlParameter("@MailAddress",MailAddress),
                                                                       new SqlParameter("@Phone",Phone)};

            string sql = "insert into SalesLT.Customer(Title,FirstName,MiddleName,LastName,CompanyName,EmailAddress,Phone,PasswordHash,ModifiedDate,PasswordSalt) values(@Gender,@FirstName,@MiddleName,@LastName,@CompanyName,@MailAddress,@Phone,'test',GETDATE(),'test')";

            try
            {
                return SqlHelper.ExecuteNonQuery(sql, parms);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, null, errMessage);
            }
        }
        /// <summary>
        ///  修改明细
        /// </summary>
        /// <param name="dicCustomerInfo">参数</param>
        /// <returns>受影响行数</returns>
        public int UpdateDetail(Dictionary<string, string> dicCustomerInfo)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string Gender = dicCustomerInfo["Gender"];
            string FirstName = dicCustomerInfo["FirstName"];
            string MiddleName = dicCustomerInfo["MiddleName"];
            string LastName = dicCustomerInfo["LastName"];
            string CompanyName = dicCustomerInfo["CompanyName"];
            string Phone = dicCustomerInfo["Phone"];
            string MailAddress = dicCustomerInfo["MailAddress"];
            int ID = Convert.ToInt32(dicCustomerInfo["ID"]);

            SqlParameter[] parms = new SqlParameter[] { new SqlParameter("@Gender", Gender),
                                                                       new SqlParameter("@FirstName",FirstName),
                                                                       new SqlParameter("@MiddleName",MiddleName),
                                                                       new SqlParameter("@LastName",LastName),
                                                                       new SqlParameter("@CompanyName",CompanyName),
                                                                       new SqlParameter("@MailAddress",MailAddress),
                                                                       new SqlParameter("@Phone",Phone),
                                                                       new SqlParameter("@ID",ID)};

            string sql = "update SalesLT.Customer set Title = @Gender,FirstName = @FirstName,MiddleName = @MiddleName,LastName = @LastName,CompanyName = @CompanyName,EmailAddress = @MailAddress,Phone = @Phone where customerid = @ID";

            try
            {
                return SqlHelper.ExecuteNonQuery(sql, parms);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, null, errMessage);
            }
        }
        /// <summary>
        ///  删除明细
        /// </summary>
        /// <param name="dicCustomerInfo">参数</param>
        /// <returns>受影响行数</returns>
        public int DeleteDetail(int ID)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            SqlParameter[] parms = new SqlParameter[] { new SqlParameter("@ID", ID) };

            string sql = "delete from SalesLT.Customer where customerid = @ID";

            try
            {
                return SqlHelper.ExecuteNonQuery(sql, parms);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, null, errMessage);
            }
        }

    }
}
