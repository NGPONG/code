using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SQLite;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WP.Demo.Common;
using WP.Demo.Model;

namespace WP.Demo.DAL
{
    public class DishInfoDAL
    {
        /// <summary>
        ///  获取数据
        /// </summary>
        /// <returns>序列化后的字节数组</returns>
        public List<byte[]> GetData()
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称 
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            StringBuilder sql = new StringBuilder();
            sql.AppendLine("select a.Did,a.DTitle,b.DTitle as DTypeTitle,a.DPrice,a.DChar");
            sql.AppendLine("from DishInfo a");
            sql.AppendLine("left join DishTypeInfo b on a.DTypeId = b.DId and b.DIsDelete = 0");
            sql.AppendLine("where a.DIsDelete = 0");

            try
            {
                DataTable dtTemp = SQLiteHelper.GetDataTable(sql.ToString());
                // 接受数据的数据模型类的集合
                List<DishInfoModel_GetData> listGetDataModel = new List<DishInfoModel_GetData>();
                for (int i = 0; i < dtTemp.Rows.Count; i++)
                {
                    listGetDataModel.Add(new DishInfoModel_GetData()
                    {
                        DId = Convert.ToString(dtTemp.Rows[i]["DId"]),
                        DTitle = Convert.ToString(dtTemp.Rows[i]["DTitle"]),
                        DTypeTitle = Convert.ToString(dtTemp.Rows[i]["DTypeTitle"]),
                        DPrice = Convert.ToString(dtTemp.Rows[i]["DPrice"]),
                        DChar = Convert.ToString(dtTemp.Rows[i]["DChar"])
                    });
                }
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<DishInfoModel_GetData>(listGetDataModel);

                return listSerializeBuff;
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
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql.ToString(), null, errMessage);
            }
        }
        /// <summary>
        ///  检查是否存在相同的菜品
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public List<byte[]> CheckHaveSameDishTitle(DishInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string DTitle = model.DTitle;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@DTitle",DTitle)
                };

            string sql = "SELECT 1 FROM DishInfo WHERE DTitle = @DTitle AND DIsDelete = 0";
            try
            {
                string resultStr = Convert.ToString(SQLiteHelper.ExecuteScalar(sql, parms));

                // 接受数据的数据模型类的集合
                List<DishInfoModel_CheckHaveSameDishTitle> listCheckHaveSameDishTitleModel = new List<DishInfoModel_CheckHaveSameDishTitle>();
                listCheckHaveSameDishTitleModel.Add(new DishInfoModel_CheckHaveSameDishTitle()
                {
                    CharacterResult = resultStr
                });

                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<DishInfoModel_CheckHaveSameDishTitle>(listCheckHaveSameDishTitleModel);

                return listSerializeBuff;
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    errMessage = objException.InnerException.Message;
                    throw new Exception(objException.InnerException.Message);
                }
                errMessage = objException.Message;
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, parms, errMessage);
            }
        }
        /// <summary>
        ///  添加数据
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int AddDishInfoDetail(DishInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string DTitle = model.DTitle;
            string DTypeId = model.DTypeId;
            string DPrice = model.DPrice;
            string DChar = model.DChar;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@DTitle",DTitle),
                    new SQLiteParameter("@DTypeId",DTypeId),
                    new SQLiteParameter("@DPrice",DPrice),
                    new SQLiteParameter("@DChar",DChar)
                };

            string sql = "insert into DishInfo(DTitle,DTypeId,DPrice,DChar,DIsDelete) values(@DTitle,@DTypeId,@DPrice,@DChar,0)";

            try
            {
                return SQLiteHelper.ExecuteNonQuery(sql, parms);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    errMessage = objException.InnerException.Message;
                    throw new Exception(objException.InnerException.Message);
                }
                errMessage = objException.Message;
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, parms, errMessage);
            }
        }
        /// <summary>
        ///  修改数据
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int UpdateDishInfoDetail(DishInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string DTitle = model.DTitle;
            string DTypeId = model.DTypeId;
            string DPrice = model.DPrice;
            string DId = model.DId;
            string DChar = model.DChar;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@DTitle",DTitle),
                    new SQLiteParameter("@DTypeId",DTypeId),
                    new SQLiteParameter("@DPrice",DPrice),
                    new SQLiteParameter("@DId",DId),
                    new SQLiteParameter("@DChar",DChar)
                };

            string sql = "UPDATE DishInfo SET DTitle = @DTitle,DTypeId = @DTypeId,DPrice = @DPrice,DChar = @DChar WHERE DId = @DId";

            try
            {
                return SQLiteHelper.ExecuteNonQuery(sql, parms);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    errMessage = objException.InnerException.Message;
                    throw new Exception(objException.InnerException.Message);
                }
                errMessage = objException.Message;
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, parms, errMessage);
            }
        }
        /// <summary>
        ///  删除数据
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int DeleteDishInfoDetail(DishInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string DId = model.DId.ToString();

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@DId",DId)
                };

            string sql = "UPDATE DishInfo SET DIsDelete = 1 WHERE DId = @DId";
            try
            {
                return SQLiteHelper.ExecuteNonQuery(sql, parms);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    errMessage = objException.InnerException.Message;
                    throw new Exception(objException.InnerException.Message);
                }
                errMessage = objException.Message;
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, parms, errMessage);
            }
        }
    }
}
