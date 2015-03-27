CodeContracts
=============

Source code for the CodeContracts tools for .NET

Code Contracts provide a language-agnostic way to express coding assumptions in .NET programs.

The contracts take the form of pre-conditions, post-conditions, and object invariants. Contracts act as checked documentation of your external and internal APIs. The contracts are used to improve testing via runtime checking, enable static contract verification, and documentation generation. Code Contracts bring the advantages of design-by-contract programming to all .NET programming languages. We currently provide three tools:
Runtime Checking. Our binary rewriter modifies a program by injecting the contracts, which are checked as part of program execution. Rewritten programs improve testability: each contract acts as an oracle, giving a test run a pass/fail indication. 

Automatic testing tools, such as Pex, take advantage of contracts to generate more meaningful unit tests by filtering out meaningless test arguments that don't satisfy the pre-conditions. 

Static Checking. Our static checker can decide if there are any contract violations without even running the program! It checks for implicit contracts, such as null dereferences and array bounds, as well as the explicit contracts. 

Documentation Generation. Our documentation generator augments existing XML doc files with contract information. There are also new style sheets that can be used with Sandcastle so that the generated documentation pages have contract sections. 

## Quick Links

* Download: [https://visualstudiogallery.msdn.microsoft.com/1ec7db13-3363-46c9-851f-1ce455f66970](https://visualstudiogallery.msdn.microsoft.com/1ec7db13-3363-46c9-851f-1ce455f66970)
* FAQ: [http://research.microsoft.com/en-us/projects/contracts/faq.aspx](http://research.microsoft.com/en-us/projects/contracts/faq.aspx)
* Forum: [http://social.msdn.microsoft.com/Forums/en-US/codecontracts/threads](http://social.msdn.microsoft.com/Forums/en-US/codecontracts/threads)
* JabbR chat room: [https://jabbr.net/#/rooms/CodeContracts](https://jabbr.net/#/rooms/CodeContracts)


How to Build the tools
==
Open CodeContracts.sln and Build

To create the installer and the nuget package, just run buildCC <version>
For instance  buildCC 1.8.10107.10

We use the convention: 
CC major version = 1.8.1
CC minor version = <month><day>.<buildInTheDay>

