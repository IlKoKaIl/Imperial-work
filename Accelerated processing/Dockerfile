FROM intel/oneapi-basekit:2025.0.2-0-devel-ubuntu24.04

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=1000

SHELL ["/bin/bash", "-c"]

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
      build-essential \
      ca-certificates \
      cmake \
      git \
      intel-oneapi-compiler-fpga \
      less \
      make \
      ninja-build \
      pkg-config \
      wget && \
    rm -rf /var/lib/apt/lists/*

RUN if ! id -u "${USERNAME}" >/dev/null 2>&1; then \
      if getent passwd "${USER_UID}" >/dev/null; then \
        useradd -m -s /bin/bash "${USERNAME}"; \
      else \
        if ! getent group "${USER_GID}" >/dev/null; then \
          groupadd --gid "${USER_GID}" "${USERNAME}"; \
        fi; \
        useradd --uid "${USER_UID}" --gid "${USER_GID}" -m -s /bin/bash "${USERNAME}"; \
      fi; \
    fi

# Force oneAPI env init in interactive shells so FPGA libs are always on linker paths.
ENV SETVARS_COMPLETED=
RUN printf '%s\n' 'source /opt/intel/oneapi/setvars.sh --force >/dev/null 2>&1 || true' > /etc/profile.d/oneapi.sh && \
    printf '%s\n' 'source /opt/intel/oneapi/setvars.sh --force >/dev/null 2>&1 || true' >> /etc/bash.bashrc

WORKDIR /workspaces
USER ${USERNAME}

CMD ["/bin/bash"]
