//---------------------------------------------
// Delegats 
// Created by Volodymyr KUKSYNOK 
// 2014
//---------------------------------------------
#pragma once
#include <vector>
#include <memory>

namespace Fregat
{
	namespace System
	{
		struct NIL {};
		
		class IArguments
		{
		public:
		    virtual ~IArguments() {}
		};
		
		template< class T1 = NIL, class T2 = NIL > class Arguments : public IArguments
		{
		public:
		    T1 arg1;
		    T2 arg2;
		
		    Arguments()
			{}
		    Arguments( T1 t_arg1 ) : arg1( t_arg1 )
			{}
		    Arguments( T1 t_arg1, T2 t_arg2 ) : arg1( t_arg1 ), arg2( t_arg2 )
			{}
		};
		
		class IContainer
		{
		public:
		    virtual void Call( IArguments* ) = 0;
		    virtual ~IContainer(){}
		};
		
		template< class T, class M > class Container : public IContainer
		{
		
		private:
		
		    typedef void (T::*U)(void);
		    T* m_class; U m_method;
		
		public:
		
		    Container()
			{}
		    Container( T* c, M m ) : m_class( c ), m_method( m )
			{}
		
		    virtual ~Container(){}
		
		    virtual void Call( IArguments* t_args )
			{
			  (m_class->*m_method)();
			}
		};
		
		template< class T, class A1 > class Container< T, void (T::*)(A1) > : public IContainer
		{
		private:
		    typedef void (T::*M)(A1);
		    typedef Arguments<A1> A;
		
		    T* m_class; M m_method;
		public:
		    Container( T* c, M m ) : m_class( c ), m_method( m )
			{}
		    virtual ~Container(){}
		
		    virtual void Call( IArguments* t_args )
			{
			    A* a = dynamic_cast< A* >( t_args );
			    //assert( a );
			    if( a ) (m_class->*m_method)( a->arg1 );
			}
		};
		
		template< class T, class A1, class A2 > class Container< T, void (T::*)(A1,A2) > : public IContainer
		{
		private:
		    typedef void (T::*M)(A1,A2);
		    typedef Arguments<A1,A2> A;
		    T* m_class; M m_method;
		public:
		    Container( T* c, M m ) : m_class( c ), m_method( m )
			{}
		    virtual ~Container(){}
		
		    virtual void Call( IArguments* t_args )
			{
			    A* a = dynamic_cast< A* >( t_args );
			    //assert( a );
			    if( a ) (m_class->*m_method)( a->arg1, a->arg2 );
			}
		};
		 
		class Delegat
		{
		private:
			std::vector<std::unique_ptr<IContainer>> m_containers;
		public:
		
		    Delegat()
			{
			}
		
		    ~Delegat()
			{
			    Clear();
			}
		
		    void Clear()
			{
				m_containers.clear();
			}
		
		    template< class T, class U > void AppendConnect(T* t_class, U t_method)
			{
				m_containers.append(std::unique_ptr<IContainer>(Container<T, U>(t_class, t_method)));
			}
		
		    void Call(void)
			{
				std::unique_ptr<Arguments<>> tmpArgs(new Arguments<>());
				for(auto m_iterator = m_containers.begin(); m_iterator != m_containers.end(); ++m_iterator)//for(auto container : m_containers)
			    {
					(*m_iterator)->Call(tmpArgs.get());
			    }
			}
		
			template< class T1 > void Call( T1 t_arg1 )
			{
			    std::unique_ptr<Arguments<T1>> tmpArgs(new Arguments<T1>(t_arg1));
			    for(auto m_iterator = m_containers.begin(); m_iterator != m_containers.end(); ++m_iterator)
			    {
			        (*m_iterator)->Call(tmpArgs);
			    }
			}
		
		    template< class T1, class T2 >  void Call( T1 t_arg1, T2 t_arg2 )
			{
				std::unique_ptr<Arguments< T1, T2 >> tmpArgs(new Arguments< T1, T2 >( t_arg1, t_arg2 ));
			    for(auto m_iterator = m_containers.begin(); m_iterator != m_containers.end(); ++m_iterator)
			    {
			        (*m_iterator)->Call(tmpArgs);
			    }
			}
		
		    bool IsHasActions()
			{
				return m_containers.size() > 0;
			}
		};
	}
}