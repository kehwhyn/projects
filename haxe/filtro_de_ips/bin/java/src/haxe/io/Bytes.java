// Generated by Haxe 4.1.1
package haxe.io;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Bytes extends haxe.lang.HxObject
{
	public Bytes(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public Bytes(int length, byte[] b)
	{
		//line 34 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		haxe.io.Bytes.__hx_ctor_haxe_io_Bytes(this, length, b);
	}
	
	
	protected static void __hx_ctor_haxe_io_Bytes(haxe.io.Bytes __hx_this, int length, byte[] b)
	{
		//line 35 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		__hx_this.length = length;
		//line 36 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		__hx_this.b = b;
	}
	
	
	public int length;
	
	public byte[] b;
	
	@Override public java.lang.String toString()
	{
		//line 512 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		try 
		{
			//line 512 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			return new java.lang.String(this.b, 0, this.length, "UTF-8");
		}
		catch (java.lang.Throwable _g)
		{
			//line 1 "?"
			java.lang.Object e = ((java.lang.Object) (haxe.Exception.caught(_g).unwrap()) );
			//line 514 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			throw ((java.lang.RuntimeException) (haxe.Exception.thrown(e)) );
		}
		
		
	}
	
	
	@Override public double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		{
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			boolean __temp_executeDef1 = true;
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			if (( field != null )) 
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				switch (field.hashCode())
				{
					case -1106363674:
					{
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						if (field.equals("length")) 
						{
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							__temp_executeDef1 = false;
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							this.length = ((int) (value) );
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							return value;
						}
						
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						break;
					}
					
					
				}
				
			}
			
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			if (__temp_executeDef1) 
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				return super.__hx_setField_f(field, value, handleProperties);
			}
			else
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		{
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			boolean __temp_executeDef1 = true;
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			if (( field != null )) 
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				switch (field.hashCode())
				{
					case 98:
					{
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						if (field.equals("b")) 
						{
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							__temp_executeDef1 = false;
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							this.b = ((byte[]) (value) );
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							return value;
						}
						
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						break;
					}
					
					
					case -1106363674:
					{
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						if (field.equals("length")) 
						{
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							__temp_executeDef1 = false;
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							this.length = ((int) (haxe.lang.Runtime.toInt(value)) );
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							return value;
						}
						
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						break;
					}
					
					
				}
				
			}
			
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			if (__temp_executeDef1) 
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				return super.__hx_setField(field, value, handleProperties);
			}
			else
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		{
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			boolean __temp_executeDef1 = true;
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			if (( field != null )) 
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				switch (field.hashCode())
				{
					case -1776922004:
					{
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						if (field.equals("toString")) 
						{
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							__temp_executeDef1 = false;
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							return ((haxe.lang.Function) (new haxe.lang.Closure(this, "toString")) );
						}
						
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						break;
					}
					
					
					case -1106363674:
					{
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						if (field.equals("length")) 
						{
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							__temp_executeDef1 = false;
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							return this.length;
						}
						
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						break;
					}
					
					
					case 98:
					{
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						if (field.equals("b")) 
						{
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							__temp_executeDef1 = false;
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							return this.b;
						}
						
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						break;
					}
					
					
				}
				
			}
			
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			if (__temp_executeDef1) 
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			else
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		{
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			boolean __temp_executeDef1 = true;
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			if (( field != null )) 
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				switch (field.hashCode())
				{
					case -1106363674:
					{
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						if (field.equals("length")) 
						{
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							__temp_executeDef1 = false;
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							return ((double) (this.length) );
						}
						
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						break;
					}
					
					
				}
				
			}
			
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			if (__temp_executeDef1) 
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			else
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_invokeField(java.lang.String field, java.lang.Object[] dynargs)
	{
		//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		{
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			boolean __temp_executeDef1 = true;
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			if (( field != null )) 
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				switch (field.hashCode())
				{
					case -1776922004:
					{
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						if (field.equals("toString")) 
						{
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							__temp_executeDef1 = false;
							//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
							return this.toString();
						}
						
						//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
						break;
					}
					
					
				}
				
			}
			
			//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
			if (__temp_executeDef1) 
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				return super.__hx_invokeField(field, dynargs);
			}
			else
			{
				//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		baseArr.push("b");
		//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		baseArr.push("length");
		//line 29 "/usr/share/haxe/std/haxe/io/Bytes.hx"
		super.__hx_getFields(baseArr);
	}
	
	
}

