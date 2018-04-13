#include <cx/string_view.hpp>
#include <wildcards/wildcards.hpp>

int main()
{
  using namespace cx::literals;

  static_assert(wildcards::match("Hallo"_sv, "Hallo"_sv), "");

  return 0;
}
