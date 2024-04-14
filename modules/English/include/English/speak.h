#pragma once

#if (defined(_WIN32) || defined(WIN64))
#ifdef ENGLISH_EXPORT
#define ENGLISH_API _declspec(dllexport)
#else
#define ENGLISH_API _declspec(dllimport)
#endif
#else
#define ENGLISH_API
#endif

namespace english {
ENGLISH_API void Speak();
} // namespace english
