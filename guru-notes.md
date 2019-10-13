## Don't use `#[bench]`

Use [criterion].

[criterion]: https://github.com/bheisler/criterion.rs

Rust has (unstable) built-in benchmarking. Criterion is better &mdash; uses more
rigorous statistics and compensates better for variations between runs.


## Don't jump to lifetimes

Just clone things. The allocator is fast.


## Implementing `Drop` is a breaking change

```
struct Bar;
struct Foo(Bar);
impl Drop for Foo { fn drop(&mut self) { } }

fn main() {
   // XXX can't destructure
   let Foo(i) = Foo(Bar);
}
```


## Know your cargo command lines

The defaults are not always what you want. Save time
by being precise with your `cargo` invocations.

```
cargo check --all
cargo test --all --no-run
cargo check --all --no-run --profile=dev
cargo test -p subproject
```


## The "turbofish"

This looks like a fish right?

```
a::<B>();
```

In a call, you want to specify generic type arguments like

```
a<B>();
```

But you must write

```
a::<B>();
```

`<` is syntactically ambiguous with "less than".

Rust programmers call this wart the "turbofish".


## Alternate debug formatting

```rust
println!("{:?}", qux);
println!("{:#?}", qux);
```

```rust
Foo { bar: 0, baz: 1 }
Foo {
    bar: 0,
    baz: 1,
}
```

https://doc.rust-lang.org/stable/std/fmt/#sign0


## Mutable aliasing


## Build without the network

```
cargo generate-lockfile
cargo fetch
cargo build --locked --offline
cargo test --locked --offline
```


## Rust CI tools

```
cargo clippy
cargo fmt
cargo outdated
cargo audit
``


## More Rust tools

https://github.com/brson/my-rust-lists/blob/master/rust-cli-tools.md


## The curious `Path::display()`

