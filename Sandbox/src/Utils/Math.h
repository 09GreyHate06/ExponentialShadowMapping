#pragma once

#define ESM_PI 3.14159265359

namespace ESM
{
	template<typename T>
	constexpr T Sqr(const T& x)
	{
		return x * x;
	}

	template<typename T>
	constexpr T Gauss(T x, T sigma)
	{
		return (T)1.0 / ((T)sqrt(2.0 * ESM_PI) * sigma) * exp(-Sqr(x) / ((T)2.0 * Sqr(sigma)));
	}

	template<typename T>
	constexpr T ApproxGaussKernelSize(T sigma)
	{
		return (T)2.0 * (T)ESM_PI * sigma;
	}
}