#pragma once

#include <functional>
#include <vector>
#include <mutex>
#include "API/Base.h"


namespace API
{
	class Requests
	{
	public:
		ARK_API static Requests& Get();

		Requests();
		~Requests();

		Requests(const Requests&) = delete;
		Requests(Requests&&) = delete;
		Requests& operator=(const Requests&) = delete;
		Requests& operator=(Requests&&) = delete;

		struct RequestSyncData {
			bool success;
			int statusCode;
			std::string result;
		};


		/**
		 * \brief Creates an async GET Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param included headers
		 */
		ARK_API bool CreateGetRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			std::vector<std::string> headers = {});

		/**
		 * \brief Creates an async GET Request that runs in another thread but calls the callback from the main thread, with timeout options
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param included headers
		 * \param included connectionTimeout in seconds (0 = default)
		 * \param included receiveTimeout in seconds (0 = default)
		 * \param included sendTimeout in seconds (0 = default)
		 */
		ARK_API bool CreateGetRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			std::vector<std::string> headers,
			long connectionTimeout, long receiveTimeout, long sendTimeout);

		/**
		 * \brief Creates an async POST Request with application/x-www-form-urlencoded content type that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param data to post
		 * \param included headers
		 */
		[[deprecated]]
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			const std::string& post_data,
			std::vector<std::string> headers = {});

		/**
		 * \brief Creates an async POST Request with application/x-www-form-urlencoded content type that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool), result(string) and , responseHeaders(std::unordered_map<std::string, std::string>), result is error code if request failed and the response otherwise
		 * \param data to post
		 * \param included headers
		 */
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string, std::unordered_map<std::string, std::string>)>& callback,
			const std::string& post_data,
			std::vector<std::string> headers = {});

		/**
		 * \brief Creates an async POST Request with application/x-www-form-urlencoded content type that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param data to post
		 * \param included headers
		 * \param included connectionTimeout in seconds (0 = default)
		 * \param included receiveTimeout in seconds (0 = default)
		 * \param included sendTimeout in seconds (0 = default)
		 */
		[[deprecated]]
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			const std::string& post_data,
			std::vector<std::string> headers,
			long connectionTimeout, long receiveTimeout, long sendTimeout);


		/**
		 * \brief Creates an async POST Request with application/x-www-form-urlencoded content type that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool), result(string) and , responseHeaders(std::unordered_map<std::string, std::string>), result is error code if request failed and the response otherwise
		 * \param data to post
		 * \param included headers
		 * \param included connectionTimeout in seconds (0 = default)
		 * \param included receiveTimeout in seconds (0 = default)
		 * \param included sendTimeout in seconds (0 = default)
		 */
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string, std::unordered_map<std::string, std::string>)>& callback,
			const std::string& post_data,
			std::vector<std::string> headers,
			long connectionTimeout, long receiveTimeout, long sendTimeout);

		/**
		 * \brief Creates an async POST Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param data to post
		 * \param content type
		 * \param included headers
		 */
		[[deprecated]]
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			const std::string& post_data,
			const std::string& content_type,
			std::vector<std::string> headers = {});

		/**
		 * \brief Creates an async POST Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool), result(string) and , responseHeaders(std::unordered_map<std::string, std::string>), result is error code if request failed and the response otherwise
		 * \param data to post
		 * \param content type
		 * \param included headers
		 */
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string, std::unordered_map<std::string, std::string>)>& callback,
			const std::string& post_data,
			const std::string& content_type,
			std::vector<std::string> headers = {});

		/**
		 * \brief Creates an async POST Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param data to post
		 * \param content type
		 * \param included headers
		 * \param included connectionTimeout in seconds (0 = default)
		 * \param included receiveTimeout in seconds (0 = default)
		 * \param included sendTimeout in seconds (0 = default)
		 */
		[[deprecated]]
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			const std::string& post_data,
			const std::string& content_type,
			std::vector<std::string> headers,
			long connectionTimeout, long receiveTimeout, long sendTimeout);

		/**
		 * \brief Creates an async POST Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool), result(string) and , responseHeaders(std::unordered_map<std::string, std::string>), result is error code if request failed and the response otherwise
		 * \param data to post
		 * \param content type
		 * \param included headers
		 * \param included connectionTimeout in seconds (0 = default)
		 * \param included receiveTimeout in seconds (0 = default)
		 * \param included sendTimeout in seconds (0 = default)
		 */
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string, std::unordered_map<std::string, std::string>)>& callback,
			const std::string& post_data,
			const std::string& content_type,
			std::vector<std::string> headers,
			long connectionTimeout, long receiveTimeout, long sendTimeout);

		/**
		 * \brief Creates an async POST Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param data key
		 * \param data value
		 * \param included headers
		 */
		[[deprecated]]
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			const std::vector<std::string>& post_ids,
			const std::vector<std::string>& post_data,
			std::vector<std::string> headers = {});

		/**
		 * \brief Creates an async POST Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool), result(string) and , responseHeaders(std::unordered_map<std::string, std::string>), result is error code if request failed and the response otherwise
		 * \param data key
		 * \param data value
		 * \param included headers
		 */
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string, std::unordered_map<std::string, std::string>)>& callback,
			const std::vector<std::string>& post_ids,
			const std::vector<std::string>& post_data,
			std::vector<std::string> headers = {});

		/**
		 * \brief Creates an async POST Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param data key
		 * \param data value
		 * \param included headers
		 * \param included connectionTimeout in seconds (0 = default)
		 * \param included receiveTimeout in seconds (0 = default)
		 * \param included sendTimeout in seconds (0 = default)
		 */
		[[deprecated]]
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			const std::vector<std::string>& post_ids,
			const std::vector<std::string>& post_data,
			std::vector<std::string> headers,
			long connectionTimeout, long receiveTimeout, long sendTimeout);

		/**
		 * \brief Creates an async POST Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool), result(string) and , responseHeaders(std::unordered_map<std::string, std::string>), result is error code if request failed and the response otherwise
		 * \param data key
		 * \param data value
		 * \param included headers
		 * \param included connectionTimeout in seconds (0 = default)
		 * \param included receiveTimeout in seconds (0 = default)
		 * \param included sendTimeout in seconds (0 = default)
		 */
		ARK_API bool CreatePostRequest(const std::string& url,
			const std::function<void(bool, std::string, std::unordered_map<std::string, std::string>)>& callback,
			const std::vector<std::string>& post_ids,
			const std::vector<std::string>& post_data,
			std::vector<std::string> headers,
			long connectionTimeout, long receiveTimeout, long sendTimeout);

		/**
		 * \brief Creates an async PATCH Request with application/x-www-form-urlencoded content type that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param data to patch
		 * \param included headers
		 */
		ARK_API bool CreatePatchRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			const std::string& patch_data,
			std::vector<std::string> headers = {});

		/**
		 * \brief Creates an async PATCH Request with application/x-www-form-urlencoded content type that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param data to patch
		 * \param included headers
		 * \param included connectionTimeout in seconds (0 = default)
		 * \param included receiveTimeout in seconds (0 = default)
		 * \param included sendTimeout in seconds (0 = default)
		 */
		ARK_API bool CreatePatchRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			const std::string& patch_data,
			std::vector<std::string> headers,
			long connectionTimeout, long receiveTimeout, long sendTimeout);

		/**
		 * \brief Creates an async PATCH Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param data to patch
		 * \param content type
		 * \param included headers
		 */
		ARK_API bool CreatePatchRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			const std::string& patch_data,
			const std::string& content_type,
			std::vector<std::string> headers = {});

		/**
		 * \brief Creates an async PATCH Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param data to patch
		 * \param content type
		 * \param included headers
		 * \param included connectionTimeout in seconds (0 = default)
		 * \param included receiveTimeout in seconds (0 = default)
		 * \param included sendTimeout in seconds (0 = default)
		 */
		ARK_API bool CreatePatchRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			const std::string& patch_data,
			const std::string& content_type,
			std::vector<std::string> headers,
			long connectionTimeout, long receiveTimeout, long sendTimeout);

		/**
		 * \brief Creates an async DELETE Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param included headers
		 */
		ARK_API bool CreateDeleteRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			std::vector<std::string> headers = {});

		/**
		 * \brief Creates an async DELETE Request that runs in another thread but calls the callback from the main thread
		 * \param request URL
		 * \param the callback function, binds sucess(bool) and result(string), result is error code if request failed and the response otherwise
		 * \param included headers
		 * \param included connectionTimeout in seconds (0 = default)
		 * \param included receiveTimeout in seconds (0 = default)
		 * \param included sendTimeout in seconds (0 = default)
		 */
		ARK_API bool CreateDeleteRequest(const std::string& url,
			const std::function<void(bool, std::string)>& callback,
			std::vector<std::string> headers,
			long connectionTimeout, long receiveTimeout, long sendTimeout);

		/**
		 * \brief Creates an sync GET Request that should NOT be called from the main game thread to avoid player timeout issues
		 * \param request URL
		 * \param included headers
		 */
		ARK_API RequestSyncData CreateGetRequestSync(const std::string& url,
			std::vector<std::string> headers = {});

		/**
		 * \brief Creates an sync GET Request that should NOT be called from the main game thread to avoid player timeout issues
		 * \param request URL
		 * \param included headers
		 * \param included connectionTimeout in seconds (0 = default)
		 * \param included receiveTimeout in seconds (0 = default)
		 * \param included sendTimeout in seconds (0 = default)
		 */
		ARK_API RequestSyncData CreateGetRequestSync(const std::string& url,
			std::vector<std::string> headers,
			long connectionTimeout, long receiveTimeout, long sendTimeout);

		static bool DownloadFile(const std::string& url, const std::string& localPath, std::vector<std::string> headers = {});
	private:
		class impl;
		std::unique_ptr<impl> pimpl;
		bool suppress_errors = false;
	};
} // namespace API
