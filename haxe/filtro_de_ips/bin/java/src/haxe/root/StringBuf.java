// Generated by Haxe 4.1.1
package haxe.root;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class StringBuf extends haxe.lang.HxObject
{
	public StringBuf(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public StringBuf()
	{
		//line 28 "/usr/share/haxe/std/java/_std/StringBuf.hx"
		haxe.root.StringBuf.__hx_ctor__StringBuf(this);
	}
	
	
	protected static void __hx_ctor__StringBuf(haxe.root.StringBuf __hx_this)
	{
		//line 29 "/usr/share/haxe/std/java/_std/StringBuf.hx"
		__hx_this.b = new java.lang.StringBuilder();
	}
	
	
	public java.lang.StringBuilder b;
	
	public <T> void add(T x)
	{
		//line 37 "/usr/share/haxe/std/java/_std/StringBuf.hx"
		if (haxe.lang.Runtime.isInt(x)) 
		{
			//line 38 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			int x1 = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (x) ))) );
			//line 39 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			java.lang.Object xd = x1;
			//line 40 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			java.lang.StringBuilder __temp_expr2 = ((java.lang.StringBuilder) (this.b.append(((java.lang.Object) (xd) ))) );
		}
		else
		{
			//line 42 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			java.lang.StringBuilder __temp_expr1 = ((java.lang.StringBuilder) (this.b.append(((java.lang.Object) (x) ))) );
		}
		
	}
	
	
	@Override public java.lang.String toString()
	{
		//line 57 "/usr/share/haxe/std/java/_std/StringBuf.hx"
		return this.b.toString();
	}
	
	
	@Override public java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
		{
			//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			boolean __temp_executeDef1 = true;
			//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			if (( field != null )) 
			{
				//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
				switch (field.hashCode())
				{
					case 98:
					{
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						if (field.equals("b")) 
						{
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							__temp_executeDef1 = false;
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							this.b = ((java.lang.StringBuilder) (value) );
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							return value;
						}
						
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						break;
					}
					
					
				}
				
			}
			
			//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			if (__temp_executeDef1) 
			{
				//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
				return super.__hx_setField(field, value, handleProperties);
			}
			else
			{
				//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
		{
			//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			boolean __temp_executeDef1 = true;
			//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			if (( field != null )) 
			{
				//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
				switch (field.hashCode())
				{
					case -1776922004:
					{
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						if (field.equals("toString")) 
						{
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							__temp_executeDef1 = false;
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							return ((haxe.lang.Function) (new haxe.lang.Closure(this, "toString")) );
						}
						
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						break;
					}
					
					
					case 98:
					{
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						if (field.equals("b")) 
						{
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							__temp_executeDef1 = false;
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							return this.b;
						}
						
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						break;
					}
					
					
					case 96417:
					{
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						if (field.equals("add")) 
						{
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							__temp_executeDef1 = false;
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							return ((haxe.lang.Function) (new haxe.lang.Closure(this, "add")) );
						}
						
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						break;
					}
					
					
				}
				
			}
			
			//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			if (__temp_executeDef1) 
			{
				//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			else
			{
				//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_invokeField(java.lang.String field, java.lang.Object[] dynargs)
	{
		//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
		{
			//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			boolean __temp_executeDef1 = true;
			//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			if (( field != null )) 
			{
				//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
				switch (field.hashCode())
				{
					case -1776922004:
					{
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						if (field.equals("toString")) 
						{
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							__temp_executeDef1 = false;
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							return this.toString();
						}
						
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						break;
					}
					
					
					case 96417:
					{
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						if (field.equals("add")) 
						{
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							__temp_executeDef1 = false;
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							this.add(((java.lang.Object) (dynargs[0]) ));
							//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
							return ((java.lang.Object) (null) );
						}
						
						//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
						break;
					}
					
					
				}
				
			}
			
			//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
			if (__temp_executeDef1) 
			{
				//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
				return super.__hx_invokeField(field, dynargs);
			}
			else
			{
				//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
		baseArr.push("b");
		//line 23 "/usr/share/haxe/std/java/_std/StringBuf.hx"
		super.__hx_getFields(baseArr);
	}
	
	
}


