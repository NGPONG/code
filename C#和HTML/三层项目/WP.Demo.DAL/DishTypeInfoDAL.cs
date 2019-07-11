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
    public class DishTypeInfoDAL
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

            string sql = "select DId,DTitle from DishTypeInfo where DIsDelete = 0";

            try
            {
                DataTable dtTemp = SQLiteHelper.GetDataTable(sql);
                // 接受数据的数据模型类的集合
                List<DishTypeInfoModel_GetData> listGetDataModel = new List<DishTypeInfoModel_GetData>();
                for (int i = 0; i < dtTemp.Rows.Count; i++)
                {
                    listGetDataModel.Add(new DishTypeInfoModel_GetData()
                    {
                        DId = Convert.ToString(dtTemp.Rows[i]["DId"]),
                        DTitle = Convert.ToString(dtTemp.Rows[i]["DTitle"]),
                    });
                }
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<DishTypeInfoModel_GetData>(listGetDataModel);

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
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, null, errMessage);
            }
        }
        /// <summary>
        ///  检查是否存在相同的菜单名
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public List<byte[]> CheckHaveSameDishTitle(DishTypeInfoModel model)
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

            string sql = "SELECT 1 FROM DishTypeInfo WHERE DTitle = @DTitle AND DIsDelete = 0";
            try
            {
                string resultStr = Convert.ToString(SQLiteHelper.ExecuteScalar(sql, parms));

                // 接受数据的数据模型类的集合
                List<DishTypeInfoModel_CheckHaveSameDishTitle> listCheckHaveSameDishTitleModel = new List<DishTypeInfoModel_CheckHaveSameDishTitle>();
                listCheckHaveSameDishTitleModel.Add(new DishTypeInfoModel_CheckHaveSameDishTitle()
                {
                    CharacterResult = resultStr
                });
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<DishTypeInfoModel_CheckHaveSameDishTitle>(listCheckHaveSameDishTitleModel);

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
        public int AddDishTypeInfoDetail(DishTypeInfoModel model)
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

            string sql = "insert into DishTypeInfo(DTitle,DIsDelete) values(@DTitle, '0')";

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
        public int UpdateDishTypeInfoDetail(DishTypeInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string DTitle = model.DTitle;
            string DId = model.DId;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@DTitle",DTitle),
                    new SQLiteParameter("@DId",DId)
                };

            string sql = "UPDATE DishTypeInfo SET DTitle = @DTitle WHERE DId = @DId";

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
        public int DeleteDishTypeInfoDetail(DishTypeInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string DId = model.DId;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@DId",DId)
                };

            string sql = "UPDATE DishTypeInfo SET DIsDelete = '1' WHERE DId = @DId";

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
