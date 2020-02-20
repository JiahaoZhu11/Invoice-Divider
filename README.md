# Invoice-Divider 2.0.1
This version reasigned the function of "Enter" and "Esc" Key.

### New Feature:
1. The "Esc" Key is disabled.
2. The "Enter" Key works in the following way:
    > When focus is at "name", if it is empty, warn; otherwise, go to "unit price".
    > When focus is at "unit price", if it is empty, go to "total price"; otherwise, go to "number".
    > When focus is at "total price", if it is empty, warn; otherwise, go to "number".
    > When focus is at "number", if anything is missing, warn and go to it; otherwise add the invoice to the list then to to "name".
