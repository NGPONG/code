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
    public class HallInfoDAL
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

            string sql = "select HId,HTitle from HallInfo where HIsDelete = 0";

            try
            {
                DataTable dtTemp = SQLiteHelper.GetDataTable(sql);
                // 接受数据的数据模型类的集合
                List<HallInfoModel_GetData> listGetDataModel = new List<HallInfoModel_GetData>();
                for (int i = 0; i < dtTemp.Rows.Count; i++)
                {
                    listGetDataModel.Add(new HallInfoModel_GetData()
                    {
                        HId = Convert.ToString(dtTemp.Rows[i]["HId"]),
                        HTitle = Convert.ToString(dtTemp.Rows[i]["HTitle"]),
                    });
                }
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<HallInfoModel_GetData>(listGetDataModel);

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
        ///  检查是否存在相同的厅包名
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public List<byte[]> CheckHaveSameHallTitle(HallInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string HTitle = model.HTitle;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@HTitle",HTitle)
                };

            string sql = "SELECT 1 FROM HallInfo WHERE HTitle = @HTitle AND HIsDelete = 0";
            try
            {
                string resultStr = Convert.ToString(SQLiteHelper.ExecuteScalar(sql, parms));

                // 接受数据的数据模型类的集合
                List<HallInfoModel_CheckHaveSameHallTitle> listCheckHaveSameHallTitleModel = new List<HallInfoModel_CheckHaveSameHallTitle>();
                listCheckHaveSameHallTitleModel.Add(new HallInfoModel_CheckHaveSameHallTitle()
                {
                    CharacterResult = resultStr
                });
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<HallInfoModel_CheckHaveSameHallTitle>(listCheckHaveSameHallTitleModel);

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
        public int AddHallInfoDetail(HallInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string HTitle = model.HTitle;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@HTitle",HTitle)
                };

            string sql = "insert into HallInfo(HTitle,HIsDelete) values(@HTitle, '0')";

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
        public int UpdateHallInfoDetail(HallInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string HTitle = model.HTitle;
            string HId = model.HId;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@HTitle",HTitle),
                    new SQLiteParameter("@HId",HId)
                };

            string sql = "UPDATE HallInfo SET HTitle = @HTitle WHERE HId = @HId";

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
        public int DeleteHallInfoDetail(HallInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string HId = model.HId;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@HId",HId)
                };

            string sql = "UPDATE HallInfo SET HIsDelete = '1' WHERE HId = @HId";

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
