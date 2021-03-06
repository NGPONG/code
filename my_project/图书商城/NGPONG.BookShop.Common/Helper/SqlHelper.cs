﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.Common.Helper
{
    public static class SqlHelper
    {
        /// <summary>
        ///  SQLite连接字符串
        /// </summary>
        //public static string SqlConnectionCharacter = ConfigurationManager.ConnectionStrings["sqlConnectionStr"].ConnectionString;
        private static string SqlConnectionCharacter = "server =.;uid=sa;pwd=kissyou199;database=book_shop3";
        /// <summary>
        ///  执行非查询sql语句
        /// </summary>
        /// <param name="sql">sql语句</param>
        /// <param name="parms">参数</param>
        /// <returns>受影响的行数</returns>
        public static int ExecuteNonQuery(string sql, params SqlParameter[] parms)
        {
            try
            {
                int result = 0;
                using (SqlConnection connection = new SqlConnection(SqlHelper.SqlConnectionCharacter))
                {
                    connection.Open();

                    using (SqlCommand cmd = connection.CreateCommand())
                    {
                        cmd.CommandText = sql;
                        // 如果有参数
                        if (parms.Length > 0)
                        {
                            cmd.Parameters.AddRange(parms);
                        }
                        using (SqlTransaction tran = connection.BeginTransaction())
                        {
                            cmd.Transaction = tran;
                            try
                            {
                                result = cmd.ExecuteNonQuery();
                                tran.Commit();
                                return result;
                            }
                            catch (Exception objException)
                            {
                                tran.Rollback();
                                if (objException.InnerException != null)
                                {
                                    throw new Exception(objException.InnerException.Message);
                                }
                                throw new Exception(objException.Message);
                            }
                        }
                    }
                }
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
        ///  执行查询语句并返回一行一列的结果
        /// </summary>
        /// <param name="sql">sql语句</param>
        /// <param name="parms">参数</param>
        /// <returns>一行一列的结果</returns>
        public static object ExecuteScalar(string sql, params SqlParameter[] parms)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(SqlHelper.SqlConnectionCharacter))
                {
                    connection.Open();

                    using (SqlCommand cmd = connection.CreateCommand())
                    {
                        cmd.CommandText = sql;
                        // 如果有参数
                        if (parms.Length > 0)
                        {
                            cmd.Parameters.AddRange(parms);
                        }
                        object objReturn = cmd.ExecuteScalar();
                        return objReturn == null ? string.Empty : objReturn;
                    }
                }
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
        public static object ExecuteScalarProc(string sql, params SqlParameter[] parms)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(SqlHelper.SqlConnectionCharacter))
                {
                    connection.Open();

                    using (SqlCommand cmd = connection.CreateCommand())
                    {
                        cmd.CommandText = sql;
                        cmd.CommandType = CommandType.StoredProcedure;
                        // 如果有参数
                        if (parms.Length > 0)
                        {
                            cmd.Parameters.AddRange(parms);
                        }
                        object objReturn = cmd.ExecuteScalar();
                        return objReturn == null ? string.Empty : objReturn;
                    }
                }
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
        ///  获取SqlDataReader
        /// </summary>
        /// <param name="sql">sql语句</param>
        /// <param name="parms">参数</param>
        /// <returns>SQLiteDataReader</returns>
        public static SqlDataReader ExecuteReader(string sql, params SqlParameter[] parms)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(SqlHelper.SqlConnectionCharacter))
                {
                    connection.Open();

                    using (SqlCommand cmd = connection.CreateCommand())
                    {
                        cmd.CommandText = sql;
                        // 如果有参数
                        if (parms.Length > 0)
                        {
                            cmd.Parameters.AddRange(parms);
                        }

                        SqlDataReader reader = cmd.ExecuteReader();
                        return reader;
                    }
                }
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
        ///  获取查询结果集
        /// </summary>
        /// <param name="sql">sql语句</param>
        /// <param name="parms">参数</param>
        /// <returns>查询结果</returns>
        public static List<T> GetDataList<T>(string sql, params SqlParameter[] parms)
            where T : new()
        {
            try
            {
                List<T> t_List = new List<T>();
                using (SqlConnection connection = new SqlConnection(SqlHelper.SqlConnectionCharacter))
                {
                    connection.Open();

                    using (SqlCommand cmd = connection.CreateCommand())
                    {
                        cmd.CommandText = sql;
                        // 如果有参数
                        if (parms.Length > 0)
                        {
                            cmd.Parameters.AddRange(parms);
                        }

                        using (SqlDataReader reader = cmd.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                T t = new T();
                                Type t_Type = t.GetType();
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    var typeProperty = t_Type.GetProperty(reader.GetName(i));
                                    typeProperty?.SetValue(t, Convert.ChangeType(reader.GetValue(i), typeProperty.PropertyType));
                                }
                                t_List.Add(t);
                            }
                        }
                    }
                }
                return t_List;
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
        ///  获取查询结果集
        /// </summary>
        /// <param name="sql">sql语句</param>
        /// <param name="parms">参数</param>
        /// <returns>查询结果</returns>
        public static DataTable GetDataTable(string sql, params SqlParameter[] parms)
        {
            try
            {
                DataTable dtResult = new DataTable();
                using (SqlConnection connection = new SqlConnection(SqlHelper.SqlConnectionCharacter))
                {
                    connection.Open();

                    using (SqlCommand cmd = connection.CreateCommand())
                    {
                        cmd.CommandText = sql;
                        // 如果有参数
                        if (parms.Length > 0)
                        {
                            cmd.Parameters.AddRange(parms);
                        }

                        using (SqlDataAdapter adapter = new SqlDataAdapter(cmd))
                        {
                            adapter.Fill(dtResult);
                        }
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
        /// <summary>
        ///  获取查询结果集
        /// </summary>
        /// <param name="sql">sql语句</param>
        /// <param name="parms">参数</param>
        /// <returns>查询结果</returns>
        public static DataTable GetDataTablProc(string sql, params SqlParameter[] parms)
        {
            try
            {
                DataTable dtResult = new DataTable();
                using (SqlConnection connection = new SqlConnection(SqlHelper.SqlConnectionCharacter))
                {
                    connection.Open();

                    using (SqlCommand cmd = connection.CreateCommand())
                    {
                        cmd.CommandText = sql;
                        cmd.CommandType = CommandType.StoredProcedure;
                        // 如果有参数
                        if (parms.Length > 0)
                        {
                            cmd.Parameters.AddRange(parms);
                        }

                        using (SqlDataAdapter adapter = new SqlDataAdapter(cmd))
                        {
                            adapter.Fill(dtResult);
                        }
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
