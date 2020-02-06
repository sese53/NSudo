﻿/*
 * PROJECT:   Mouri Internal Library Essentials
 * FILE:      Mile.Windows.h
 * PURPOSE:   Mouri Internal Library Essentials Definition for Windows
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
 */

#ifndef MILE_WINDOWS
#define MILE_WINDOWS

#ifndef __cplusplus
#error "[Mile.Windows] You should use a C++ compiler."
#endif // !__cplusplus

#include <Windows.h>

/**
 * Retrieves a handle to the default heap of the calling process. This handle
 * can then be used in subsequent calls to the heap functions.
 *
 * @return The handle to the calling process's heap.
 * @remark For more information, see GetProcessHeap.
 */
EXTERN_C HANDLE WINAPI MileGetProcessHeap();

/**
 * Allocates a block of memory from a heap. The allocated memory is not
 * movable.
 *
 * @param hHeap A handle to the heap from which the memory will be allocated.
 * @param dwFlags The heap allocation options.
 * @param dwBytes The number of bytes to be allocated.
 * @param lpNewMem A pointer to the allocated memory block.
 * @return HRESULT. If the function succeeds, the return value is S_OK.
 * @remark For more information, see HeapAlloc.
 */
EXTERN_C HRESULT WINAPI MileHeapAlloc(
    _In_ HANDLE hHeap,
    _In_ DWORD dwFlags,
    _In_ SIZE_T dwBytes,
    _Out_ LPVOID* lpNewMem);

/**
 * Reallocates a block of memory from a heap. This function enables you to
 * resize a memory block and change other memory block properties. The
 * allocated memory is not movable.
 *
 * @param hHeap A handle to the heap from which the memory is to be
 *              reallocated.
 * @param dwFlags The heap reallocation options.
 * @param lpMem A pointer to the block of memory that the function reallocates.
 *              This pointer is returned by an earlier call to the
 *              MileHeapAlloc or MileHeapReAlloc function.
 * @param dwBytes The new size of the memory block, in bytes. A memory block's
 *                size can be increased or decreased by using this function.
 * @param lpNewMem A pointer to the allocated memory block.
 * @return HRESULT. If the function succeeds, the return value is S_OK. If the
 *         function fails, the original memory is not freed, and the original
 *         handle and pointer are still valid.
 * @remark For more information, see HeapReAlloc.
 */
EXTERN_C HRESULT WINAPI MileHeapReAlloc(
    _Inout_ HANDLE hHeap,
    _In_ DWORD dwFlags,
    _In_ LPVOID lpMem,
    _In_ SIZE_T dwBytes,
    _Out_ LPVOID* lpNewMem);

/**
 * Frees a memory block allocated from a heap by the MileHeapAlloc or
 * MileHeapReAlloc function.
 *
 * @param hHeap A handle to the heap whose memory block is to be freed.
 * @param dwFlags The heap free options.
 * @param lpMem A pointer to the memory block to be freed.
 * @return HRESULT. If the function succeeds, the return value is S_OK.
 * @remark For more information, see HeapFree.
 */
EXTERN_C HRESULT WINAPI MileHeapFree(
    _Inout_ HANDLE hHeap,
    _In_ DWORD dwFlags,
    _In_ LPVOID lpMem);

/**
 * Allocates a block of memory from the default heap of the calling process.
 * The allocated memory will be initialized to zero. The allocated memory is
 * not movable.
 *
 * @param Size The number of bytes to be allocated.
 * @param Block A pointer to the allocated memory block.
 * @return HRESULT. If the function succeeds, the return value is S_OK.
 */
EXTERN_C HRESULT WINAPI MileAllocMemory(
    _In_ SIZE_T Size,
    _Out_ LPVOID* Block);

/**
 * Reallocates a block of memory from the default heap of the calling process.
 * If the reallocation request is for a larger size, the additional region of
 * memory beyond the original size be initialized to zero. This function
 * enables you to resize a memory block and change other memory block
 * properties. The allocated memory is not movable.
 *
 * @param OldBlock A pointer to the block of memory that the function
 *                 reallocates. This pointer is returned by an earlier call to
 *                 the MileAllocMemory or MileReAllocMemory function.
 * @param NewSize The new size of the memory block, in bytes. A memory block's
 *                size can be increased or decreased by using this function.
 * @param NewBlock A pointer to the allocated memory block.
 * @return HRESULT. If the function succeeds, the return value is S_OK. If the
 *         function fails, the original memory is not freed, and the original
 *         handle and pointer are still valid.
 */
EXTERN_C HRESULT WINAPI MileReAllocMemory(
    _In_ PVOID OldBlock,
    _In_ SIZE_T NewSize,
    _Out_ LPVOID* NewBlock);

/**
 * Frees a memory block allocated from a heap by the MileAllocMemory or
 * MileReAllocMemory function.
 *
 * @param Block A pointer to the memory block to be freed. This pointer is
 *              returned by the AllocMemory or ReAllocMemory function. If this
 *              pointer is nullptr, the behavior is undefined.
 * @return HRESULT. If the function succeeds, the return value is S_OK.
 */
EXTERN_C HRESULT WINAPI MileFreeMemory(
    _In_ LPVOID Block);

/**
 * Enables or disables privileges in the specified access token. Enabling or
 * disabling privileges in an access token requires TOKEN_ADJUST_PRIVILEGES
 * access.
 *
 * @param TokenHandle A handle to the access token that contains the privileges
 *                    to be modified. The handle must have
 *                    TOKEN_ADJUST_PRIVILEGES access to the token. If the
 *                    PreviousState parameter is not NULL, the handle must also
 *                    have TOKEN_QUERY access.
 * @param DisableAllPrivileges Specifies whether the function disables all of
 *                             the token's privileges. If this value is TRUE,
 *                             the function disables all privileges and ignores
 *                             the NewState parameter. If it is FALSE, the
 *                             function modifies privileges based on the
 *                             information pointed to by the NewState
 *                             parameter.
 * @param NewState A pointer to a TOKEN_PRIVILEGES structure that specifies an
 *                 array of privileges and their attributes. If
 *                 DisableAllPrivileges is TRUE, the function ignores this
 *                 parameter.
 * @param BufferLength Specifies the size, in bytes, of the buffer pointed to
 *                     by the PreviousState parameter. This parameter can be
 *                     zero if the PreviousState parameter is NULL.
 * @param PreviousState A pointer to a buffer that the function fills with a
 *                      TOKEN_PRIVILEGES structure that contains the previous
 *                      state of any privileges that the function modifies.
 *                      This parameter can be NULL.
 * @param ReturnLength A pointer to a variable that receives the required size,
 *                     in bytes, of the buffer pointed to by the PreviousState
 *                     parameter. This parameter can be NULL if PreviousState
 *                     is NULL.
 * @return HRESULT. If the function succeeds, the return value is S_OK.
 * @remark For more information, see AdjustTokenPrivileges.
 */
EXTERN_C HRESULT WINAPI MileAdjustTokenPrivileges(
    _In_ HANDLE TokenHandle,
    _In_ BOOL DisableAllPrivileges,
    _In_opt_ PTOKEN_PRIVILEGES NewState,
    _In_ DWORD BufferLength,
    _Out_opt_ PTOKEN_PRIVILEGES PreviousState,
    _Out_opt_ PDWORD ReturnLength);

/**
 * Retrieves a specified type of information about an access token. The calling
 * process must have appropriate access rights to obtain the information.
 *
 * @param TokenHandle A handle to an access token from which information is
 *                    retrieved.
 * @param TokenInformationClass Specifies a value from the
 *                              TOKEN_INFORMATION_CLASS enumerated type to
 *                              identify the type of information the
 *                              function retrieves.
 * @param TokenInformation A pointer to a buffer the function fills with the
 *                         requested information.
 * @param TokenInformationLength Specifies the size, in bytes, of the buffer
 *                               pointed to by the TokenInformation parameter.
 * @param ReturnLength A pointer to a variable that receives the number of
 *                     bytes needed for the buffer pointed to by the
 *                     TokenInformation parameter.
 * @return HRESULT. If the method succeeds, the return value is S_OK.
 * @remark For more information, see GetTokenInformation.
 */
EXTERN_C HRESULT WINAPI MileGetTokenInformation(
    _In_ HANDLE TokenHandle,
    _In_ TOKEN_INFORMATION_CLASS TokenInformationClass,
    _Out_opt_ LPVOID TokenInformation,
    _In_ DWORD TokenInformationLength,
    _Out_ PDWORD ReturnLength);

/**
 * Sets various types of information for a specified access token. The
 * information that this function sets replaces existing information. The
 * calling process must have appropriate access rights to set the information.
 *
 * @param TokenHandle A handle to the access token for which information is to
 *                    be set.
 * @param TokenInformationClass A value from the TOKEN_INFORMATION_CLASS
 *                              enumerated type that identifies the type of
 *                              information the function sets. The valid values
 *                              from TOKEN_INFORMATION_CLASS are described in
 *                              the TokenInformation parameter.
 * @param TokenInformation A pointer to a buffer that contains the information
 *                         set in the access token.
 * @param TokenInformationLength Specifies the length, in bytes, of the buffer
 *                               pointed to by TokenInformation.
 * @return HRESULT. If the method succeeds, the return value is S_OK.
 * @remark For more information, see SetTokenInformation.
 */
EXTERN_C HRESULT WINAPI MileSetTokenInformation(
    _In_ HANDLE TokenHandle,
    _In_ TOKEN_INFORMATION_CLASS TokenInformationClass,
    _In_ LPVOID TokenInformation,
    _In_ DWORD TokenInformationLength);

/**
 * Retrieves a specified type of information about an access token. The calling
 * process must have appropriate access rights to obtain the information.
 *
 * @param TokenHandle A handle to an access token from which information is
 *                    retrieved.
 * @param TokenInformationClass Specifies a value from the
 *                              TOKEN_INFORMATION_CLASS enumerated type to
 *                              identify the type of information the function
 *                              retrieves.
 * @param OutputInformation A pointer to a buffer the function fills with the
 *                          requested information. When you have finished using
 *                          the information, free it by calling the
 *                          MileFreeMemory function. You should also set the
 *                          pointer to nullptr.
 * @return HRESULT. If the method succeeds, the return value is S_OK.
 * @remark For more information, see GetTokenInformation.
 */
EXTERN_C HRESULT WINAPI MileGetTokenInformationWithMemory(
    _In_ HANDLE TokenHandle,
    _In_ TOKEN_INFORMATION_CLASS TokenInformationClass,
    _Out_ PVOID* OutputInformation);

/**
 * Enables or disables privileges in the specified access token.
 *
 * @param TokenHandle A handle to the access token that contains the privileges
 *                    to be modified. The handle must have
 *                    TOKEN_ADJUST_PRIVILEGES access to the token.
 * @param Privileges A pointer to an array of LUID_AND_ATTRIBUTES structures
 *                   that specifies an array of privileges and their
 *                   attributes. Each structure contains the LUID and
 *                   attributes of a privilege. To get the name of the
 *                   privilege associated with a LUID, call the
 *                   MileGetPrivilegeValue function, passing the address of the
 *                   LUID as the value of the lpLuid parameter. The attributes
 *                   of a privilege can be a combination of the following
 *                   values.
 *                   SE_PRIVILEGE_ENABLED
 *                       The function enables the privilege.
 *                   SE_PRIVILEGE_REMOVED
 *                       The privilege is removed from the list of privileges
 *                       in the token.
 *                   None
 *                       The function disables the privilege.
 * @param PrivilegeCount The number of entries in the Privileges array.
 * @return HRESULT. If the method succeeds, the return value is S_OK.
 * @remark For more information, see AdjustTokenPrivileges.
 */
EXTERN_C HRESULT WINAPI MileAdjustTokenPrivilegesSimple(
    _In_ HANDLE TokenHandle,
    _In_ PLUID_AND_ATTRIBUTES Privileges,
    _In_ DWORD PrivilegeCount);

/**
 * Enables or disables all privileges in the specified access token.
 *
 * @param TokenHandle A handle to the access token that contains the privileges
 *                    to be modified. The handle must have
 *                    TOKEN_ADJUST_PRIVILEGES access to the token.
 * @param Attributes The attributes of all privileges can be a combination of
 *                   the following values.
 *                   SE_PRIVILEGE_ENABLED
 *                       The function enables the privilege.
 *                   SE_PRIVILEGE_REMOVED
 *                       The privilege is removed from the list of privileges
 *                       in the token.
 *                   None
 *                       The function disables the privilege.
 * @return HRESULT. If the method succeeds, the return value is S_OK.
 */
EXTERN_C HRESULT WINAPI MileAdjustTokenAllPrivileges(
    _In_ HANDLE TokenHandle,
    _In_ DWORD Attributes);

/**
 * Retrieves the locally unique identifier (LUID) used on the local system to
 * locally represent the specified privilege name.
 *
 * @param Name A pointer to a null-terminated string that specifies the name of
 *             the privilege, as defined in the Winnt.h header file. For
 *             example, this parameter could specify the constant,
 *             SE_SECURITY_NAME, or its corresponding string,
 *             "SeSecurityPrivilege".
 * @param Value A pointer to a variable that receives the LUID by which the
 *              privilege is known on the local system.
 * @return HRESULT. If the method succeeds, the return value is S_OK.
 * @remark For more information, see LookupPrivilegeValue.
 */
EXTERN_C HRESULT WINAPI MileGetPrivilegeValue(
    _In_ LPCWSTR Name,
    _Out_ PLUID Value);

/**
 * Starts a service if not started and retrieves the current status of the
 * specified service.
 *
 * @param ServiceName The name of the service to be started. This is the name
 *                    specified by the ServiceName parameter of the
 *                    CreateService function when the service object was
 *                    created, not the service display name that is shown by
 *                    user interface applications to identify the service. The
 *                    maximum string length is 256 characters. The service
 *                    control manager database preserves the case of the
 *                    characters, but service name comparisons are always case
 *                    insensitive. Forward-slash (/) and backslash (\) are
 *                    invalid service name characters.
 * @param ServiceStatus A pointer to the process status information for a
 *                      service.
 * @return HRESULT. If the method succeeds, the return value is S_OK.
 */
EXTERN_C HRESULT WINAPI MileStartService(
    _In_ LPCWSTR ServiceName,
    _Out_ LPSERVICE_STATUS_PROCESS ServiceStatus);

/**
 * Retrieves the number of milliseconds that have elapsed since the system was
 * started.
 *
 * @return The number of milliseconds.
 */
EXTERN_C ULONGLONG WINAPI MileGetTickCount();

/**
 * Closes an open object handle.
 *
 * @param hObject A valid handle to an open object.
 * @return HRESULT. If the function succeeds, the return value is S_OK.
 * @remark For more information, see CloseHandle.
 */
EXTERN_C HRESULT WINAPI MileCloseHandle(
    _In_ HANDLE hObject);

/**
 * Obtains the primary access token of the logged-on user specified by the
 * session ID. To call this function successfully, the calling application must
 * be running within the context of the LocalSystem account and have the
 * SE_TCB_NAME privilege.
 *
 * @param SessionId A Remote Desktop Services session identifier.
 * @param TokenHandle If the function succeeds, receives a pointer to the token
 *                    handle for the logged-on user. Note that you must call
 *                    the MileCloseHandle function to close this handle.
 * @return HRESULT. If the method succeeds, the return value is S_OK.
 * @remark For more information, see WTSQueryUserToken.
 */
EXTERN_C HRESULT WINAPI MileCreateSessionToken(
    _In_ DWORD SessionId,
    _Out_ PHANDLE TokenHandle);

/**
 * Creates a new access token that is a restricted version of an existing
 * access token. The restricted token can have disabled security identifiers
 * (SIDs), deleted privileges, and a list of restricting SIDs. For more
 * information, see Restricted Tokens.
 *
 * @param ExistingTokenHandle A handle to a primary or impersonation token. The
 *                            token can also be a restricted token. The handle
 *                            must have TOKEN_DUPLICATE access to the token.
 * @param Flags Specifies additional privilege options. This parameter can be
 *              zero or a combination of the following values.
 *              DISABLE_MAX_PRIVILEGE
 *                  Disables all privileges in the new token except the
 *                  SeChangeNotifyPrivilege privilege. If this value is
 *                  specified, the DeletePrivilegeCount and PrivilegesToDelete
 *                  parameters are ignored.
 *              SANDBOX_INERT
 *                  If this value is used, the system does not check AppLocker
 *                  rules or apply Software Restriction Policies. For
 *                  AppLocker, this flag disables checks for all four rule
 *                  collections: Executable, Windows Installer, Script, and
 *                  DLL.
 *              LUA_TOKEN
 *                  The new token is a LUA token.
 *              WRITE_RESTRICTED
 *                  The new token contains restricting SIDs that are considered
 *                  only when evaluating write access.
 * @param DisableSidCount Specifies the number of entries in the SidsToDisable
 *                        array.
 * @param SidsToDisable A pointer to an array of SID_AND_ATTRIBUTES structures
 *                      that specify the deny-only SIDs in the restricted
 *                      token.
 * @param DeletePrivilegeCount Specifies the number of entries in the
 *                             PrivilegesToDelete array.
 * @param PrivilegesToDelete A pointer to an array of LUID_AND_ATTRIBUTES
 *                           structures that specify the privileges to delete
 *                           in the restricted token.
 * @param RestrictedSidCount Specifies the number of entries in the
 *                           SidsToRestrict array.
 * @param SidsToRestrict A pointer to an array of SID_AND_ATTRIBUTES structures
 *                       that specify a list of restricting SIDs for the new
 *                       token.
 * @param NewTokenHandle A pointer to a variable that receives a handle to the
 *                       new restricted token.
 * @return HRESULT. If the method succeeds, the return value is S_OK.
 * @remark For more information, see CreateRestrictedToken.
 */
EXTERN_C HRESULT WINAPI MileCreateRestrictedToken(
    _In_ HANDLE ExistingTokenHandle,
    _In_ DWORD Flags,
    _In_ DWORD DisableSidCount,
    _In_opt_ PSID_AND_ATTRIBUTES SidsToDisable,
    _In_ DWORD DeletePrivilegeCount,
    _In_opt_ PLUID_AND_ATTRIBUTES PrivilegesToDelete,
    _In_ DWORD RestrictedSidCount,
    _In_opt_ PSID_AND_ATTRIBUTES SidsToRestrict,
    _Out_ PHANDLE NewTokenHandle);

/**
 * Gets the identifier of the Local Security Authority process.
 *
 * @param ProcessId The identifier of the Local Security Authority process.
 * @return HRESULT. If the method succeeds, the return value is S_OK.
 */
EXTERN_C HRESULT WINAPI MileGetLsassProcessId(
    _Out_ PDWORD ProcessId);

#endif // !MILE_WINDOWS