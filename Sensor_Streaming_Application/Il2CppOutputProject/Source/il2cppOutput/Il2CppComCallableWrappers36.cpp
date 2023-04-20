#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <stdint.h>

#include "codegen/il2cpp-codegen.h"
#include "vm/CachedCCWBase.h"
#include "os/Unity/UnityPlatformConfigure.h"
#include "il2cpp-object-internals.h"

template <typename R>
struct VirtFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};

// System.Char[]
struct CharU5BU5D_t4CC6ABF0AD71BEC97E3C2F1E9C5677E46D3A75C2;
// System.Collections.IDictionary
struct IDictionary_t1BD5C1546718A374EA8122FBD6C6EE45331E8CE7;
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t855F09649EA34DEE7C1B6F088E0538E3CCC3F196;
// System.Exception
struct Exception_t;
// System.IntPtr[]
struct IntPtrU5BU5D_t4DC01DCB9A6DF6C9792A6513595D7A11E637DCDD;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_t4A754D86B0F784B18CBC36C073BA564BED109770;
// System.String
struct String_t;
// System.Threading.CancellationTokenSource
struct CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE;
// System.Threading.SynchronizationContext
struct SynchronizationContext_t06AEFE2C7CFCFC242D0A5729A74464AF18CF84E7;
// System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>
struct TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9;
// System.Void
struct Void_t22962CB4C05B1D89B55A6E1139F0E87A90987017;

IL2CPP_EXTERN_C RuntimeClass* String_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C const RuntimeMethod* TaskToAsyncInfoAdapter_4_Cancel_m8AFA0487A6F4A11F51F70A5896CEB9C9F39B740B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TaskToAsyncInfoAdapter_4_Close_m37FD921301AC2AE11BBDEB9CC54F1136B0DE305B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TaskToAsyncInfoAdapter_4_get_ErrorCode_m1AFFACF8C280B77D9308BDA82753EF1B5BD1A2A9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TaskToAsyncInfoAdapter_4_get_Id_m78A85BFD7E4439A700B18EC654E3664E72ED29E7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TaskToAsyncInfoAdapter_4_get_Status_mB83131E0817E07671A0E505628C877FF418619E3_RuntimeMethod_var;
IL2CPP_EXTERN_C const uint32_t IAsyncInfo_Cancel_m71EA200C07A5E2B5A9BAE4BC2AB00EFF1D3AB5A8_CCW_TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper_TaskToAsyncInfoAdapter_4_Cancel_m8AFA0487A6F4A11F51F70A5896CEB9C9F39B740B_MetadataUsageId;
IL2CPP_EXTERN_C const uint32_t IAsyncInfo_Close_m197A13662E7E9A888B0E3FFAFDBA15410AA850E7_CCW_TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper_TaskToAsyncInfoAdapter_4_Close_m37FD921301AC2AE11BBDEB9CC54F1136B0DE305B_MetadataUsageId;
IL2CPP_EXTERN_C const uint32_t IAsyncInfo_get_ErrorCode_m9A8D01260F4211B8E794B3FC73D212F3F8CAB584_CCW_TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper_TaskToAsyncInfoAdapter_4_get_ErrorCode_m1AFFACF8C280B77D9308BDA82753EF1B5BD1A2A9_MetadataUsageId;
IL2CPP_EXTERN_C const uint32_t IAsyncInfo_get_Id_mFB9E7E5D042A091EEA5ADBBB479329CE1248351B_CCW_TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper_TaskToAsyncInfoAdapter_4_get_Id_m78A85BFD7E4439A700B18EC654E3664E72ED29E7_MetadataUsageId;
IL2CPP_EXTERN_C const uint32_t IAsyncInfo_get_Status_m27500B7322807C29A220BDCBBD407C066EEF5671_CCW_TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper_TaskToAsyncInfoAdapter_4_get_Status_mB83131E0817E07671A0E505628C877FF418619E3_MetadataUsageId;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Object


// System.String
struct String_t  : public RuntimeObject
{
public:
	// System.Int32 System.String::m_stringLength
	int32_t ___m_stringLength_0;
	// System.Char System.String::m_firstChar
	Il2CppChar ___m_firstChar_1;

public:
	inline static int32_t get_offset_of_m_stringLength_0() { return static_cast<int32_t>(offsetof(String_t, ___m_stringLength_0)); }
	inline int32_t get_m_stringLength_0() const { return ___m_stringLength_0; }
	inline int32_t* get_address_of_m_stringLength_0() { return &___m_stringLength_0; }
	inline void set_m_stringLength_0(int32_t value)
	{
		___m_stringLength_0 = value;
	}

	inline static int32_t get_offset_of_m_firstChar_1() { return static_cast<int32_t>(offsetof(String_t, ___m_firstChar_1)); }
	inline Il2CppChar get_m_firstChar_1() const { return ___m_firstChar_1; }
	inline Il2CppChar* get_address_of_m_firstChar_1() { return &___m_firstChar_1; }
	inline void set_m_firstChar_1(Il2CppChar value)
	{
		___m_firstChar_1 = value;
	}
};

struct String_t_StaticFields
{
public:
	// System.String System.String::Empty
	String_t* ___Empty_5;

public:
	inline static int32_t get_offset_of_Empty_5() { return static_cast<int32_t>(offsetof(String_t_StaticFields, ___Empty_5)); }
	inline String_t* get_Empty_5() const { return ___Empty_5; }
	inline String_t** get_address_of_Empty_5() { return &___Empty_5; }
	inline void set_Empty_5(String_t* value)
	{
		___Empty_5 = value;
		Il2CppCodeGenWriteBarrier((void**)(&___Empty_5), (void*)value);
	}
};


// System.ValueType
struct ValueType_t4D0C27076F7C36E76190FB3328E232BCB1CD1FFF  : public RuntimeObject
{
public:

public:
};

// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t4D0C27076F7C36E76190FB3328E232BCB1CD1FFF_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t4D0C27076F7C36E76190FB3328E232BCB1CD1FFF_marshaled_com
{
};

// System.Enum
struct Enum_t2AF27C02B8653AE29442467390005ABC74D8F521  : public ValueType_t4D0C27076F7C36E76190FB3328E232BCB1CD1FFF
{
public:

public:
};

struct Enum_t2AF27C02B8653AE29442467390005ABC74D8F521_StaticFields
{
public:
	// System.Char[] System.Enum::enumSeperatorCharArray
	CharU5BU5D_t4CC6ABF0AD71BEC97E3C2F1E9C5677E46D3A75C2* ___enumSeperatorCharArray_0;

public:
	inline static int32_t get_offset_of_enumSeperatorCharArray_0() { return static_cast<int32_t>(offsetof(Enum_t2AF27C02B8653AE29442467390005ABC74D8F521_StaticFields, ___enumSeperatorCharArray_0)); }
	inline CharU5BU5D_t4CC6ABF0AD71BEC97E3C2F1E9C5677E46D3A75C2* get_enumSeperatorCharArray_0() const { return ___enumSeperatorCharArray_0; }
	inline CharU5BU5D_t4CC6ABF0AD71BEC97E3C2F1E9C5677E46D3A75C2** get_address_of_enumSeperatorCharArray_0() { return &___enumSeperatorCharArray_0; }
	inline void set_enumSeperatorCharArray_0(CharU5BU5D_t4CC6ABF0AD71BEC97E3C2F1E9C5677E46D3A75C2* value)
	{
		___enumSeperatorCharArray_0 = value;
		Il2CppCodeGenWriteBarrier((void**)(&___enumSeperatorCharArray_0), (void*)value);
	}
};

// Native definition for P/Invoke marshalling of System.Enum
struct Enum_t2AF27C02B8653AE29442467390005ABC74D8F521_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.Enum
struct Enum_t2AF27C02B8653AE29442467390005ABC74D8F521_marshaled_com
{
};

// System.Int32
struct Int32_t585191389E07734F19F3156FF88FB3EF4800D102 
{
public:
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;

public:
	inline static int32_t get_offset_of_m_value_0() { return static_cast<int32_t>(offsetof(Int32_t585191389E07734F19F3156FF88FB3EF4800D102, ___m_value_0)); }
	inline int32_t get_m_value_0() const { return ___m_value_0; }
	inline int32_t* get_address_of_m_value_0() { return &___m_value_0; }
	inline void set_m_value_0(int32_t value)
	{
		___m_value_0 = value;
	}
};


// System.IntPtr
struct IntPtr_t 
{
public:
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;

public:
	inline static int32_t get_offset_of_m_value_0() { return static_cast<int32_t>(offsetof(IntPtr_t, ___m_value_0)); }
	inline void* get_m_value_0() const { return ___m_value_0; }
	inline void** get_address_of_m_value_0() { return &___m_value_0; }
	inline void set_m_value_0(void* value)
	{
		___m_value_0 = value;
	}
};

struct IntPtr_t_StaticFields
{
public:
	// System.IntPtr System.IntPtr::Zero
	intptr_t ___Zero_1;

public:
	inline static int32_t get_offset_of_Zero_1() { return static_cast<int32_t>(offsetof(IntPtr_t_StaticFields, ___Zero_1)); }
	inline intptr_t get_Zero_1() const { return ___Zero_1; }
	inline intptr_t* get_address_of_Zero_1() { return &___Zero_1; }
	inline void set_Zero_1(intptr_t value)
	{
		___Zero_1 = value;
	}
};


// System.Exception
struct Exception_t  : public RuntimeObject
{
public:
	// System.String System.Exception::_className
	String_t* ____className_1;
	// System.String System.Exception::_message
	String_t* ____message_2;
	// System.Collections.IDictionary System.Exception::_data
	RuntimeObject* ____data_3;
	// System.Exception System.Exception::_innerException
	Exception_t * ____innerException_4;
	// System.String System.Exception::_helpURL
	String_t* ____helpURL_5;
	// System.Object System.Exception::_stackTrace
	RuntimeObject * ____stackTrace_6;
	// System.String System.Exception::_stackTraceString
	String_t* ____stackTraceString_7;
	// System.String System.Exception::_remoteStackTraceString
	String_t* ____remoteStackTraceString_8;
	// System.Int32 System.Exception::_remoteStackIndex
	int32_t ____remoteStackIndex_9;
	// System.Object System.Exception::_dynamicMethods
	RuntimeObject * ____dynamicMethods_10;
	// System.Int32 System.Exception::_HResult
	int32_t ____HResult_11;
	// System.String System.Exception::_source
	String_t* ____source_12;
	// System.Runtime.Serialization.SafeSerializationManager System.Exception::_safeSerializationManager
	SafeSerializationManager_t4A754D86B0F784B18CBC36C073BA564BED109770 * ____safeSerializationManager_13;
	// System.Diagnostics.StackTrace[] System.Exception::captured_traces
	StackTraceU5BU5D_t855F09649EA34DEE7C1B6F088E0538E3CCC3F196* ___captured_traces_14;
	// System.IntPtr[] System.Exception::native_trace_ips
	IntPtrU5BU5D_t4DC01DCB9A6DF6C9792A6513595D7A11E637DCDD* ___native_trace_ips_15;

public:
	inline static int32_t get_offset_of__className_1() { return static_cast<int32_t>(offsetof(Exception_t, ____className_1)); }
	inline String_t* get__className_1() const { return ____className_1; }
	inline String_t** get_address_of__className_1() { return &____className_1; }
	inline void set__className_1(String_t* value)
	{
		____className_1 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____className_1), (void*)value);
	}

	inline static int32_t get_offset_of__message_2() { return static_cast<int32_t>(offsetof(Exception_t, ____message_2)); }
	inline String_t* get__message_2() const { return ____message_2; }
	inline String_t** get_address_of__message_2() { return &____message_2; }
	inline void set__message_2(String_t* value)
	{
		____message_2 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____message_2), (void*)value);
	}

	inline static int32_t get_offset_of__data_3() { return static_cast<int32_t>(offsetof(Exception_t, ____data_3)); }
	inline RuntimeObject* get__data_3() const { return ____data_3; }
	inline RuntimeObject** get_address_of__data_3() { return &____data_3; }
	inline void set__data_3(RuntimeObject* value)
	{
		____data_3 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____data_3), (void*)value);
	}

	inline static int32_t get_offset_of__innerException_4() { return static_cast<int32_t>(offsetof(Exception_t, ____innerException_4)); }
	inline Exception_t * get__innerException_4() const { return ____innerException_4; }
	inline Exception_t ** get_address_of__innerException_4() { return &____innerException_4; }
	inline void set__innerException_4(Exception_t * value)
	{
		____innerException_4 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____innerException_4), (void*)value);
	}

	inline static int32_t get_offset_of__helpURL_5() { return static_cast<int32_t>(offsetof(Exception_t, ____helpURL_5)); }
	inline String_t* get__helpURL_5() const { return ____helpURL_5; }
	inline String_t** get_address_of__helpURL_5() { return &____helpURL_5; }
	inline void set__helpURL_5(String_t* value)
	{
		____helpURL_5 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____helpURL_5), (void*)value);
	}

	inline static int32_t get_offset_of__stackTrace_6() { return static_cast<int32_t>(offsetof(Exception_t, ____stackTrace_6)); }
	inline RuntimeObject * get__stackTrace_6() const { return ____stackTrace_6; }
	inline RuntimeObject ** get_address_of__stackTrace_6() { return &____stackTrace_6; }
	inline void set__stackTrace_6(RuntimeObject * value)
	{
		____stackTrace_6 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____stackTrace_6), (void*)value);
	}

	inline static int32_t get_offset_of__stackTraceString_7() { return static_cast<int32_t>(offsetof(Exception_t, ____stackTraceString_7)); }
	inline String_t* get__stackTraceString_7() const { return ____stackTraceString_7; }
	inline String_t** get_address_of__stackTraceString_7() { return &____stackTraceString_7; }
	inline void set__stackTraceString_7(String_t* value)
	{
		____stackTraceString_7 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____stackTraceString_7), (void*)value);
	}

	inline static int32_t get_offset_of__remoteStackTraceString_8() { return static_cast<int32_t>(offsetof(Exception_t, ____remoteStackTraceString_8)); }
	inline String_t* get__remoteStackTraceString_8() const { return ____remoteStackTraceString_8; }
	inline String_t** get_address_of__remoteStackTraceString_8() { return &____remoteStackTraceString_8; }
	inline void set__remoteStackTraceString_8(String_t* value)
	{
		____remoteStackTraceString_8 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____remoteStackTraceString_8), (void*)value);
	}

	inline static int32_t get_offset_of__remoteStackIndex_9() { return static_cast<int32_t>(offsetof(Exception_t, ____remoteStackIndex_9)); }
	inline int32_t get__remoteStackIndex_9() const { return ____remoteStackIndex_9; }
	inline int32_t* get_address_of__remoteStackIndex_9() { return &____remoteStackIndex_9; }
	inline void set__remoteStackIndex_9(int32_t value)
	{
		____remoteStackIndex_9 = value;
	}

	inline static int32_t get_offset_of__dynamicMethods_10() { return static_cast<int32_t>(offsetof(Exception_t, ____dynamicMethods_10)); }
	inline RuntimeObject * get__dynamicMethods_10() const { return ____dynamicMethods_10; }
	inline RuntimeObject ** get_address_of__dynamicMethods_10() { return &____dynamicMethods_10; }
	inline void set__dynamicMethods_10(RuntimeObject * value)
	{
		____dynamicMethods_10 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____dynamicMethods_10), (void*)value);
	}

	inline static int32_t get_offset_of__HResult_11() { return static_cast<int32_t>(offsetof(Exception_t, ____HResult_11)); }
	inline int32_t get__HResult_11() const { return ____HResult_11; }
	inline int32_t* get_address_of__HResult_11() { return &____HResult_11; }
	inline void set__HResult_11(int32_t value)
	{
		____HResult_11 = value;
	}

	inline static int32_t get_offset_of__source_12() { return static_cast<int32_t>(offsetof(Exception_t, ____source_12)); }
	inline String_t* get__source_12() const { return ____source_12; }
	inline String_t** get_address_of__source_12() { return &____source_12; }
	inline void set__source_12(String_t* value)
	{
		____source_12 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____source_12), (void*)value);
	}

	inline static int32_t get_offset_of__safeSerializationManager_13() { return static_cast<int32_t>(offsetof(Exception_t, ____safeSerializationManager_13)); }
	inline SafeSerializationManager_t4A754D86B0F784B18CBC36C073BA564BED109770 * get__safeSerializationManager_13() const { return ____safeSerializationManager_13; }
	inline SafeSerializationManager_t4A754D86B0F784B18CBC36C073BA564BED109770 ** get_address_of__safeSerializationManager_13() { return &____safeSerializationManager_13; }
	inline void set__safeSerializationManager_13(SafeSerializationManager_t4A754D86B0F784B18CBC36C073BA564BED109770 * value)
	{
		____safeSerializationManager_13 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____safeSerializationManager_13), (void*)value);
	}

	inline static int32_t get_offset_of_captured_traces_14() { return static_cast<int32_t>(offsetof(Exception_t, ___captured_traces_14)); }
	inline StackTraceU5BU5D_t855F09649EA34DEE7C1B6F088E0538E3CCC3F196* get_captured_traces_14() const { return ___captured_traces_14; }
	inline StackTraceU5BU5D_t855F09649EA34DEE7C1B6F088E0538E3CCC3F196** get_address_of_captured_traces_14() { return &___captured_traces_14; }
	inline void set_captured_traces_14(StackTraceU5BU5D_t855F09649EA34DEE7C1B6F088E0538E3CCC3F196* value)
	{
		___captured_traces_14 = value;
		Il2CppCodeGenWriteBarrier((void**)(&___captured_traces_14), (void*)value);
	}

	inline static int32_t get_offset_of_native_trace_ips_15() { return static_cast<int32_t>(offsetof(Exception_t, ___native_trace_ips_15)); }
	inline IntPtrU5BU5D_t4DC01DCB9A6DF6C9792A6513595D7A11E637DCDD* get_native_trace_ips_15() const { return ___native_trace_ips_15; }
	inline IntPtrU5BU5D_t4DC01DCB9A6DF6C9792A6513595D7A11E637DCDD** get_address_of_native_trace_ips_15() { return &___native_trace_ips_15; }
	inline void set_native_trace_ips_15(IntPtrU5BU5D_t4DC01DCB9A6DF6C9792A6513595D7A11E637DCDD* value)
	{
		___native_trace_ips_15 = value;
		Il2CppCodeGenWriteBarrier((void**)(&___native_trace_ips_15), (void*)value);
	}
};

struct Exception_t_StaticFields
{
public:
	// System.Object System.Exception::s_EDILock
	RuntimeObject * ___s_EDILock_0;

public:
	inline static int32_t get_offset_of_s_EDILock_0() { return static_cast<int32_t>(offsetof(Exception_t_StaticFields, ___s_EDILock_0)); }
	inline RuntimeObject * get_s_EDILock_0() const { return ___s_EDILock_0; }
	inline RuntimeObject ** get_address_of_s_EDILock_0() { return &___s_EDILock_0; }
	inline void set_s_EDILock_0(RuntimeObject * value)
	{
		___s_EDILock_0 = value;
		Il2CppCodeGenWriteBarrier((void**)(&___s_EDILock_0), (void*)value);
	}
};

// Native definition for P/Invoke marshalling of System.Exception
struct Exception_t_marshaled_pinvoke
{
	char* ____className_1;
	char* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_pinvoke* ____innerException_4;
	char* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	char* ____stackTraceString_7;
	char* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	char* ____source_12;
	SafeSerializationManager_t4A754D86B0F784B18CBC36C073BA564BED109770 * ____safeSerializationManager_13;
	StackTraceU5BU5D_t855F09649EA34DEE7C1B6F088E0538E3CCC3F196* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
};
// Native definition for COM marshalling of System.Exception
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className_1;
	Il2CppChar* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_com* ____innerException_4;
	Il2CppChar* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	Il2CppChar* ____stackTraceString_7;
	Il2CppChar* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	Il2CppChar* ____source_12;
	SafeSerializationManager_t4A754D86B0F784B18CBC36C073BA564BED109770 * ____safeSerializationManager_13;
	StackTraceU5BU5D_t855F09649EA34DEE7C1B6F088E0538E3CCC3F196* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
};

// System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>
struct TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9  : public RuntimeObject
{
public:
	// System.Threading.CancellationTokenSource System.Threading.Tasks.TaskToAsyncInfoAdapter`4::_cancelTokenSource
	CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE * ____cancelTokenSource_0;
	// System.UInt32 System.Threading.Tasks.TaskToAsyncInfoAdapter`4::_id
	uint32_t ____id_1;
	// System.Exception System.Threading.Tasks.TaskToAsyncInfoAdapter`4::_error
	Exception_t * ____error_2;
	// System.Int32 modreq(System.Runtime.CompilerServices.IsVolatile) System.Threading.Tasks.TaskToAsyncInfoAdapter`4::_state
	int32_t ____state_3;
	// System.Object System.Threading.Tasks.TaskToAsyncInfoAdapter`4::_dataContainer
	RuntimeObject * ____dataContainer_4;
	// TCompletedHandler System.Threading.Tasks.TaskToAsyncInfoAdapter`4::_completedHandler
	RuntimeObject * ____completedHandler_5;
	// TProgressHandler System.Threading.Tasks.TaskToAsyncInfoAdapter`4::_progressHandler
	RuntimeObject * ____progressHandler_6;
	// System.Threading.SynchronizationContext System.Threading.Tasks.TaskToAsyncInfoAdapter`4::_startingContext
	SynchronizationContext_t06AEFE2C7CFCFC242D0A5729A74464AF18CF84E7 * ____startingContext_7;

public:
	inline static int32_t get_offset_of__cancelTokenSource_0() { return static_cast<int32_t>(offsetof(TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9, ____cancelTokenSource_0)); }
	inline CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE * get__cancelTokenSource_0() const { return ____cancelTokenSource_0; }
	inline CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE ** get_address_of__cancelTokenSource_0() { return &____cancelTokenSource_0; }
	inline void set__cancelTokenSource_0(CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE * value)
	{
		____cancelTokenSource_0 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____cancelTokenSource_0), (void*)value);
	}

	inline static int32_t get_offset_of__id_1() { return static_cast<int32_t>(offsetof(TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9, ____id_1)); }
	inline uint32_t get__id_1() const { return ____id_1; }
	inline uint32_t* get_address_of__id_1() { return &____id_1; }
	inline void set__id_1(uint32_t value)
	{
		____id_1 = value;
	}

	inline static int32_t get_offset_of__error_2() { return static_cast<int32_t>(offsetof(TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9, ____error_2)); }
	inline Exception_t * get__error_2() const { return ____error_2; }
	inline Exception_t ** get_address_of__error_2() { return &____error_2; }
	inline void set__error_2(Exception_t * value)
	{
		____error_2 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____error_2), (void*)value);
	}

	inline static int32_t get_offset_of__state_3() { return static_cast<int32_t>(offsetof(TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9, ____state_3)); }
	inline int32_t get__state_3() const { return ____state_3; }
	inline int32_t* get_address_of__state_3() { return &____state_3; }
	inline void set__state_3(int32_t value)
	{
		____state_3 = value;
	}

	inline static int32_t get_offset_of__dataContainer_4() { return static_cast<int32_t>(offsetof(TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9, ____dataContainer_4)); }
	inline RuntimeObject * get__dataContainer_4() const { return ____dataContainer_4; }
	inline RuntimeObject ** get_address_of__dataContainer_4() { return &____dataContainer_4; }
	inline void set__dataContainer_4(RuntimeObject * value)
	{
		____dataContainer_4 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____dataContainer_4), (void*)value);
	}

	inline static int32_t get_offset_of__completedHandler_5() { return static_cast<int32_t>(offsetof(TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9, ____completedHandler_5)); }
	inline RuntimeObject * get__completedHandler_5() const { return ____completedHandler_5; }
	inline RuntimeObject ** get_address_of__completedHandler_5() { return &____completedHandler_5; }
	inline void set__completedHandler_5(RuntimeObject * value)
	{
		____completedHandler_5 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____completedHandler_5), (void*)value);
	}

	inline static int32_t get_offset_of__progressHandler_6() { return static_cast<int32_t>(offsetof(TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9, ____progressHandler_6)); }
	inline RuntimeObject * get__progressHandler_6() const { return ____progressHandler_6; }
	inline RuntimeObject ** get_address_of__progressHandler_6() { return &____progressHandler_6; }
	inline void set__progressHandler_6(RuntimeObject * value)
	{
		____progressHandler_6 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____progressHandler_6), (void*)value);
	}

	inline static int32_t get_offset_of__startingContext_7() { return static_cast<int32_t>(offsetof(TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9, ____startingContext_7)); }
	inline SynchronizationContext_t06AEFE2C7CFCFC242D0A5729A74464AF18CF84E7 * get__startingContext_7() const { return ____startingContext_7; }
	inline SynchronizationContext_t06AEFE2C7CFCFC242D0A5729A74464AF18CF84E7 ** get_address_of__startingContext_7() { return &____startingContext_7; }
	inline void set__startingContext_7(SynchronizationContext_t06AEFE2C7CFCFC242D0A5729A74464AF18CF84E7 * value)
	{
		____startingContext_7 = value;
		Il2CppCodeGenWriteBarrier((void**)(&____startingContext_7), (void*)value);
	}
};


// Windows.Foundation.AsyncStatus
struct AsyncStatus_tBDA7F4CE333BAE130A8BB6DF88FBC68E6A54340E 
{
public:
	// System.Int32 Windows.Foundation.AsyncStatus::value__
	int32_t ___value___2;

public:
	inline static int32_t get_offset_of_value___2() { return static_cast<int32_t>(offsetof(AsyncStatus_tBDA7F4CE333BAE130A8BB6DF88FBC68E6A54340E, ___value___2)); }
	inline int32_t get_value___2() const { return ___value___2; }
	inline int32_t* get_address_of_value___2() { return &___value___2; }
	inline void set_value___2(int32_t value)
	{
		___value___2 = value;
	}
};

// Windows.Foundation.IAsyncInfo
struct NOVTABLE IAsyncInfo_t9B58E0D0A013D06029CDEAE127A910A69D13FBB5 : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IAsyncInfo_get_Id_mFB9E7E5D042A091EEA5ADBBB479329CE1248351B(uint32_t* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IAsyncInfo_get_Status_m27500B7322807C29A220BDCBBD407C066EEF5671(int32_t* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IAsyncInfo_get_ErrorCode_m9A8D01260F4211B8E794B3FC73D212F3F8CAB584(int32_t* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IAsyncInfo_Cancel_m71EA200C07A5E2B5A9BAE4BC2AB00EFF1D3AB5A8() = 0;
	virtual il2cpp_hresult_t STDCALL IAsyncInfo_Close_m197A13662E7E9A888B0E3FFAFDBA15410AA850E7() = 0;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif


// System.UInt32 System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>::get_Id()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t TaskToAsyncInfoAdapter_4_get_Id_m78A85BFD7E4439A700B18EC654E3664E72ED29E7_gshared (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __this, const RuntimeMethod* method);
// Windows.Foundation.AsyncStatus System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>::get_Status()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t TaskToAsyncInfoAdapter_4_get_Status_mB83131E0817E07671A0E505628C877FF418619E3_gshared (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __this, const RuntimeMethod* method);
// System.Exception System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>::get_ErrorCode()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t * TaskToAsyncInfoAdapter_4_get_ErrorCode_m1AFFACF8C280B77D9308BDA82753EF1B5BD1A2A9_gshared (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __this, const RuntimeMethod* method);
// System.Void System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>::Cancel()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TaskToAsyncInfoAdapter_4_Cancel_m8AFA0487A6F4A11F51F70A5896CEB9C9F39B740B_gshared (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __this, const RuntimeMethod* method);
// System.Void System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>::Close()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TaskToAsyncInfoAdapter_4_Close_m37FD921301AC2AE11BBDEB9CC54F1136B0DE305B_gshared (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __this, const RuntimeMethod* method);

// System.UInt32 System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>::get_Id()
inline uint32_t TaskToAsyncInfoAdapter_4_get_Id_m78A85BFD7E4439A700B18EC654E3664E72ED29E7 (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __this, const RuntimeMethod* method)
{
	return ((  uint32_t (*) (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 *, const RuntimeMethod*))TaskToAsyncInfoAdapter_4_get_Id_m78A85BFD7E4439A700B18EC654E3664E72ED29E7_gshared)(__this, method);
}
// Windows.Foundation.AsyncStatus System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>::get_Status()
inline int32_t TaskToAsyncInfoAdapter_4_get_Status_mB83131E0817E07671A0E505628C877FF418619E3 (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 *, const RuntimeMethod*))TaskToAsyncInfoAdapter_4_get_Status_mB83131E0817E07671A0E505628C877FF418619E3_gshared)(__this, method);
}
// System.Exception System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>::get_ErrorCode()
inline Exception_t * TaskToAsyncInfoAdapter_4_get_ErrorCode_m1AFFACF8C280B77D9308BDA82753EF1B5BD1A2A9 (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __this, const RuntimeMethod* method)
{
	return ((  Exception_t * (*) (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 *, const RuntimeMethod*))TaskToAsyncInfoAdapter_4_get_ErrorCode_m1AFFACF8C280B77D9308BDA82753EF1B5BD1A2A9_gshared)(__this, method);
}
// System.Void System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>::Cancel()
inline void TaskToAsyncInfoAdapter_4_Cancel_m8AFA0487A6F4A11F51F70A5896CEB9C9F39B740B (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __this, const RuntimeMethod* method)
{
	((  void (*) (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 *, const RuntimeMethod*))TaskToAsyncInfoAdapter_4_Cancel_m8AFA0487A6F4A11F51F70A5896CEB9C9F39B740B_gshared)(__this, method);
}
// System.Void System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>::Close()
inline void TaskToAsyncInfoAdapter_4_Close_m37FD921301AC2AE11BBDEB9CC54F1136B0DE305B (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __this, const RuntimeMethod* method)
{
	((  void (*) (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 *, const RuntimeMethod*))TaskToAsyncInfoAdapter_4_Close_m37FD921301AC2AE11BBDEB9CC54F1136B0DE305B_gshared)(__this, method);
}

// COM Callable Wrapper for System.Threading.Tasks.TaskToAsyncInfoAdapter`4<System.Object,System.Object,System.Boolean,System.VoidValueTypeParameter>
struct TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper IL2CPP_FINAL : il2cpp::vm::CachedCCWBase<TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper>, IAsyncInfo_t9B58E0D0A013D06029CDEAE127A910A69D13FBB5
{
	inline TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper(RuntimeObject* obj) : il2cpp::vm::CachedCCWBase<TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper>(obj) {}

	virtual il2cpp_hresult_t STDCALL QueryInterface(const Il2CppGuid& iid, void** object) IL2CPP_OVERRIDE
	{
		if (::memcmp(&iid, &Il2CppIUnknown::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIInspectable::IID, sizeof(Il2CppGuid)) == 0
		 || ::memcmp(&iid, &Il2CppIAgileObject::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = GetIdentity();
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIManagedObjectHolder::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIManagedObjectHolder*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &IAsyncInfo_t9B58E0D0A013D06029CDEAE127A910A69D13FBB5::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<IAsyncInfo_t9B58E0D0A013D06029CDEAE127A910A69D13FBB5*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIMarshal::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIMarshal*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		if (::memcmp(&iid, &Il2CppIWeakReferenceSource::IID, sizeof(Il2CppGuid)) == 0)
		{
			*object = static_cast<Il2CppIWeakReferenceSource*>(this);
			AddRefImpl();
			return IL2CPP_S_OK;
		}

		*object = NULL;
		return IL2CPP_E_NOINTERFACE;
	}

	virtual uint32_t STDCALL AddRef() IL2CPP_OVERRIDE
	{
		return AddRefImpl();
	}

	virtual uint32_t STDCALL Release() IL2CPP_OVERRIDE
	{
		return ReleaseImpl();
	}

	virtual il2cpp_hresult_t STDCALL GetIids(uint32_t* iidCount, Il2CppGuid** iids) IL2CPP_OVERRIDE
	{
		Il2CppGuid* interfaceIds = il2cpp_codegen_marshal_allocate_array<Il2CppGuid>(1);
		interfaceIds[0] = IAsyncInfo_t9B58E0D0A013D06029CDEAE127A910A69D13FBB5::IID;

		*iidCount = 1;
		*iids = interfaceIds;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL GetRuntimeClassName(Il2CppHString* className) IL2CPP_OVERRIDE
	{
		return GetRuntimeClassNameImpl(className);
	}

	virtual il2cpp_hresult_t STDCALL GetTrustLevel(int32_t* trustLevel) IL2CPP_OVERRIDE
	{
		return ComObjectBase::GetTrustLevel(trustLevel);
	}

	virtual il2cpp_hresult_t STDCALL IAsyncInfo_get_Id_mFB9E7E5D042A091EEA5ADBBB479329CE1248351B(uint32_t* comReturnValue) IL2CPP_OVERRIDE
	{
		static bool s_Il2CppMethodInitialized;
		if (!s_Il2CppMethodInitialized)
		{
			il2cpp_codegen_initialize_method (IAsyncInfo_get_Id_mFB9E7E5D042A091EEA5ADBBB479329CE1248351B_CCW_TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper_TaskToAsyncInfoAdapter_4_get_Id_m78A85BFD7E4439A700B18EC654E3664E72ED29E7_MetadataUsageId);
			s_Il2CppMethodInitialized = true;
		}
		il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

		// Managed method invocation
		uint32_t returnValue;
		try
		{
			TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __thisValue = (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 *)GetManagedObjectInline();
			returnValue = TaskToAsyncInfoAdapter_4_get_Id_m78A85BFD7E4439A700B18EC654E3664E72ED29E7(__thisValue, TaskToAsyncInfoAdapter_4_get_Id_m78A85BFD7E4439A700B18EC654E3664E72ED29E7_RuntimeMethod_var);
		}
		catch (const Il2CppExceptionWrapper& ex)
		{
			memset(comReturnValue, 0, sizeof(*comReturnValue));
			String_t* exceptionStr = NULL;
			try
			{
				exceptionStr = VirtFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, ex.ex);
			}
			catch (const Il2CppExceptionWrapper&)
			{
				exceptionStr = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->get_Empty_5();
			}
			il2cpp_codegen_store_exception_info(ex.ex, exceptionStr);
			return ex.ex->hresult;
		}

		*comReturnValue = returnValue;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL IAsyncInfo_get_Status_m27500B7322807C29A220BDCBBD407C066EEF5671(int32_t* comReturnValue) IL2CPP_OVERRIDE
	{
		static bool s_Il2CppMethodInitialized;
		if (!s_Il2CppMethodInitialized)
		{
			il2cpp_codegen_initialize_method (IAsyncInfo_get_Status_m27500B7322807C29A220BDCBBD407C066EEF5671_CCW_TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper_TaskToAsyncInfoAdapter_4_get_Status_mB83131E0817E07671A0E505628C877FF418619E3_MetadataUsageId);
			s_Il2CppMethodInitialized = true;
		}
		il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

		// Managed method invocation
		int32_t returnValue;
		try
		{
			TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __thisValue = (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 *)GetManagedObjectInline();
			returnValue = TaskToAsyncInfoAdapter_4_get_Status_mB83131E0817E07671A0E505628C877FF418619E3(__thisValue, TaskToAsyncInfoAdapter_4_get_Status_mB83131E0817E07671A0E505628C877FF418619E3_RuntimeMethod_var);
		}
		catch (const Il2CppExceptionWrapper& ex)
		{
			memset(comReturnValue, 0, sizeof(*comReturnValue));
			String_t* exceptionStr = NULL;
			try
			{
				exceptionStr = VirtFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, ex.ex);
			}
			catch (const Il2CppExceptionWrapper&)
			{
				exceptionStr = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->get_Empty_5();
			}
			il2cpp_codegen_store_exception_info(ex.ex, exceptionStr);
			return ex.ex->hresult;
		}

		*comReturnValue = returnValue;
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL IAsyncInfo_get_ErrorCode_m9A8D01260F4211B8E794B3FC73D212F3F8CAB584(int32_t* comReturnValue) IL2CPP_OVERRIDE
	{
		static bool s_Il2CppMethodInitialized;
		if (!s_Il2CppMethodInitialized)
		{
			il2cpp_codegen_initialize_method (IAsyncInfo_get_ErrorCode_m9A8D01260F4211B8E794B3FC73D212F3F8CAB584_CCW_TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper_TaskToAsyncInfoAdapter_4_get_ErrorCode_m1AFFACF8C280B77D9308BDA82753EF1B5BD1A2A9_MetadataUsageId);
			s_Il2CppMethodInitialized = true;
		}
		il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

		// Managed method invocation
		Exception_t * returnValue;
		try
		{
			TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __thisValue = (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 *)GetManagedObjectInline();
			returnValue = TaskToAsyncInfoAdapter_4_get_ErrorCode_m1AFFACF8C280B77D9308BDA82753EF1B5BD1A2A9(__thisValue, TaskToAsyncInfoAdapter_4_get_ErrorCode_m1AFFACF8C280B77D9308BDA82753EF1B5BD1A2A9_RuntimeMethod_var);
		}
		catch (const Il2CppExceptionWrapper& ex)
		{
			memset(comReturnValue, 0, sizeof(*comReturnValue));
			String_t* exceptionStr = NULL;
			try
			{
				exceptionStr = VirtFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, ex.ex);
			}
			catch (const Il2CppExceptionWrapper&)
			{
				exceptionStr = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->get_Empty_5();
			}
			il2cpp_codegen_store_exception_info(ex.ex, exceptionStr);
			return ex.ex->hresult;
		}

		*comReturnValue = (returnValue != NULL ? reinterpret_cast<RuntimeException*>(returnValue)->hresult : IL2CPP_S_OK);
		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL IAsyncInfo_Cancel_m71EA200C07A5E2B5A9BAE4BC2AB00EFF1D3AB5A8() IL2CPP_OVERRIDE
	{
		static bool s_Il2CppMethodInitialized;
		if (!s_Il2CppMethodInitialized)
		{
			il2cpp_codegen_initialize_method (IAsyncInfo_Cancel_m71EA200C07A5E2B5A9BAE4BC2AB00EFF1D3AB5A8_CCW_TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper_TaskToAsyncInfoAdapter_4_Cancel_m8AFA0487A6F4A11F51F70A5896CEB9C9F39B740B_MetadataUsageId);
			s_Il2CppMethodInitialized = true;
		}
		il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

		// Managed method invocation
		try
		{
			TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __thisValue = (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 *)GetManagedObjectInline();
			TaskToAsyncInfoAdapter_4_Cancel_m8AFA0487A6F4A11F51F70A5896CEB9C9F39B740B(__thisValue, TaskToAsyncInfoAdapter_4_Cancel_m8AFA0487A6F4A11F51F70A5896CEB9C9F39B740B_RuntimeMethod_var);
		}
		catch (const Il2CppExceptionWrapper& ex)
		{
			String_t* exceptionStr = NULL;
			try
			{
				exceptionStr = VirtFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, ex.ex);
			}
			catch (const Il2CppExceptionWrapper&)
			{
				exceptionStr = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->get_Empty_5();
			}
			il2cpp_codegen_store_exception_info(ex.ex, exceptionStr);
			return ex.ex->hresult;
		}

		return IL2CPP_S_OK;
	}

	virtual il2cpp_hresult_t STDCALL IAsyncInfo_Close_m197A13662E7E9A888B0E3FFAFDBA15410AA850E7() IL2CPP_OVERRIDE
	{
		static bool s_Il2CppMethodInitialized;
		if (!s_Il2CppMethodInitialized)
		{
			il2cpp_codegen_initialize_method (IAsyncInfo_Close_m197A13662E7E9A888B0E3FFAFDBA15410AA850E7_CCW_TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper_TaskToAsyncInfoAdapter_4_Close_m37FD921301AC2AE11BBDEB9CC54F1136B0DE305B_MetadataUsageId);
			s_Il2CppMethodInitialized = true;
		}
		il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

		// Managed method invocation
		try
		{
			TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 * __thisValue = (TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9 *)GetManagedObjectInline();
			TaskToAsyncInfoAdapter_4_Close_m37FD921301AC2AE11BBDEB9CC54F1136B0DE305B(__thisValue, TaskToAsyncInfoAdapter_4_Close_m37FD921301AC2AE11BBDEB9CC54F1136B0DE305B_RuntimeMethod_var);
		}
		catch (const Il2CppExceptionWrapper& ex)
		{
			String_t* exceptionStr = NULL;
			try
			{
				exceptionStr = VirtFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, ex.ex);
			}
			catch (const Il2CppExceptionWrapper&)
			{
				exceptionStr = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->get_Empty_5();
			}
			il2cpp_codegen_store_exception_info(ex.ex, exceptionStr);
			return ex.ex->hresult;
		}

		return IL2CPP_S_OK;
	}
};

IL2CPP_EXTERN_C Il2CppIUnknown* CreateComCallableWrapperFor_TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9(RuntimeObject* obj)
{
	void* memory = il2cpp::utils::Memory::Malloc(sizeof(TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper));
	if (memory == NULL)
	{
		il2cpp_codegen_raise_out_of_memory_exception();
	}

	return static_cast<Il2CppIManagedObjectHolder*>(new(memory) TaskToAsyncInfoAdapter_4_t99E829DEFA55BD468C6182AE40E2484E083EE0B9_ComCallableWrapper(obj));
}
