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
    public class MemberTypeInfoDAL
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

            string sql = "select MId,MTitle,MDiscount from  MemberTypeInfo where MIsDelete = 0 ORDER BY MDiscount";

            try
            {
                DataTable dtTemp = SQLiteHelper.GetDataTable(sql);
                // 接受数据的数据模型类的集合
                List<MemberTypeInfoModel_GetData> listGetDataModel = new List<MemberTypeInfoModel_GetData>();
                for (int i = 0; i < dtTemp.Rows.Count; i++)
                {
                    listGetDataModel.Add(new MemberTypeInfoModel_GetData()
                    {
                        MId = Convert.ToInt32(dtTemp.Rows[i]["MId"]),
                        MTitle = Convert.ToString(dtTemp.Rows[i]["MTitle"]),
                        MDiscount = Convert.ToString(dtTemp.Rows[i]["MDiscount"])
                    });
                }
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<MemberTypeInfoModel_GetData>(listGetDataModel);

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
        ///  检查是否存在相同的折扣
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public List<byte[]> CheckHaveSameDiscountTitle(MemberTypeInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MTitle = model.MTitle;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MTitle",MTitle)
                };

            string sql = "SELECT 1 FROM MemberTypeInfo WHERE MTitle = @MTitle AND MIsDelete = 0";
            try
            {
                string resultStr = Convert.ToString(SQLiteHelper.ExecuteScalar(sql, parms));

                // 接受数据的数据模型类的集合
                List<MemberTypeInfoModel_CheckHaveSameDiscountTitle> listCheckHaveSameDiscountTitleModel = new List<MemberTypeInfoModel_CheckHaveSameDiscountTitle>();
                listCheckHaveSameDiscountTitleModel.Add(new MemberTypeInfoModel_CheckHaveSameDiscountTitle()
                {
                    CharacterResult = resultStr
                });
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<MemberTypeInfoModel_CheckHaveSameDiscountTitle>(listCheckHaveSameDiscountTitleModel);

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
        public int AddMemberTypeInfoDetail(MemberTypeInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MTitle = model.MTitle;
            string MDiscount = model.MDiscount;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MTitle",MTitle),
                    new SQLiteParameter("@MDiscount",MDiscount)
                };

            string sql = "insert into MemberTypeInfo(MTitle,MDiscount,MIsDelete) values(@MTitle,@MDiscount,0)";

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
        public int UpdateMemberTypeInfoDetail(MemberTypeInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MTitle = model.MTitle;
            string MDiscount = model.MDiscount;
            string MId = model.MId.ToString();

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MTitle",MTitle),
                    new SQLiteParameter("@MDiscount",MDiscount),
                    new SQLiteParameter("@MId",MId)
                };

            string sql = "UPDATE MemberTypeInfo SET MTitle = @MTitle,MDiscount = @MDiscount WHERE MId = @MId";

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
        public int DeleteMemberTypeInfoDetail(MemberTypeInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MId = model.MId.ToString();

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MId",MId)
                };

            string sql = "UPDATE MemberTypeInfo SET MIsDelete = 1 WHERE MId = @MId";
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
