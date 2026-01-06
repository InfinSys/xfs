
#include <iostream>
#include <string>

#include"xfs/path/interface/path_policy.hpp"
#include"xfs/path/interface/system_path.hpp"
#include"xfs/platform/win32/path/policy.hpp"

template <typename T>
using FileSystemPath = xfs::path::FileSystemPath<T>;

template <typename T>
using WindowsPathPolicy = xfs::win32::path::WindowsPathPolicy<T>;

// Development demonstration
class DemoPath : public FileSystemPath<WindowsPathPolicy<wchar_t>> {
public:
    DemoPath(const StringType& path) noexcept
        : pathStr{path}
    {
        //
    }

private:
    StringType pathStr;
};

int main(int argc, char* argv[])
{
    //\\//
    //

    //constexpr const wchar_t* tempDir = L"C:\\Users\\TEMP\\xfs\\..\\xfs_install\\.";
    const std::wstring tDir = L"C:\\Users\\TEMP\\xfs\\..\\xfs_install\\.";
    
    DemoPath demo{tDir};
    //

    return 0;
}
