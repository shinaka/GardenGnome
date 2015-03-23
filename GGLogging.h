#pragma once
#define IS_TESTING 1

#if IS_TESTING == 1
#define SLOG(string_literal) Serial.println(string_literal)
#else
#define SLOG(string_literal)
#endif