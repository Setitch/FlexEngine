#pragma once
#if COMPILE_VULKAN

IGNORE_WARNINGS_PUSH
#include <vulkan/vulkan.hpp>
IGNORE_WARNINGS_POP

#include "VDeleter.hpp"

namespace flex
{
	namespace vk
	{
		struct VulkanDevice;
		struct FrameBuffer;

		class VulkanRenderPass
		{
		public:
			VulkanRenderPass(VulkanDevice* device);
			~VulkanRenderPass();

			void Create(
				const char* passName,
				VkRenderPassCreateInfo* createInfo,
				const std::vector<VkImageView>& attachmentImageViews,
				u32 frameBufferWidth,
				u32 frameBufferHeight);

			void Create(
				const std::vector<VkImageLayout>& finalLayouts = {}, // VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL
				const std::vector<VkImageLayout>& initialLayouts = {}, // VK_IMAGE_LAYOUT_UNDEFINED
				VkImageLayout finalDepthLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
				VkImageLayout initialDepthLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);

			void Register(
				const char* passName,
				const std::vector<FrameBufferAttachmentID>& targtColorAttachmentIDs,
				FrameBufferAttachmentID targtDepthAttachmentID,
				const std::vector<FrameBufferAttachmentID>& sampledAttachmentIDs);

			void RegisterForColorAndDepth(
				const char* passName,
				FrameBufferAttachmentID targetColorAttachmentID,
				FrameBufferAttachmentID targetDepthAttachmentID,
				const std::vector<FrameBufferAttachmentID>& sampledAttachmentIDs);

			void RegisterForMultiColorAndDepth(
				const char* passName,
				const std::vector<FrameBufferAttachmentID>& targetColorAttachmentIDs,
				FrameBufferAttachmentID targetDepthAttachmentID,
				const std::vector<FrameBufferAttachmentID>& sampledAttachmentIDs);

			void RegisterForDepthOnly(
				const char* passName,
				FrameBufferAttachmentID targetDepthAttachmentID,
				const std::vector<FrameBufferAttachmentID>& sampledAttachmentIDs);

			void RegisterForColorOnly(
				const char* passName,
				FrameBufferAttachmentID targetColorAttachmentID,
				const std::vector<FrameBufferAttachmentID>& sampledAttachmentIDs);

			VkRenderPass* Replace();
			operator VkRenderPass();

			void Begin(VkCommandBuffer cmdBuf, VkClearValue* clearValues, u32 clearValueCount);
			void Begin_WithFrameBuffer(VkCommandBuffer cmdBuf, VkClearValue* clearValues, u32 clearValueCount, FrameBuffer* targetFrameBuffer);

			void End();

			bool bCreateFrameBuffer = true;

		private:
			friend class VulkanRenderer;

			void Begin(VkCommandBuffer cmdBuf, VkClearValue* clearValues, u32 clearValueCount, FrameBuffer* targetFrameBuffer);

			VulkanDevice* m_VulkanDevice = nullptr;

			// Registered values
			bool m_bRegistered = false;
			std::vector<VkImageLayout> m_TargetColorAttachmentInitialLayouts;
			std::vector<VkImageLayout> m_TargetColorAttachmentFinalLayouts;
			VkImageLayout m_TargetDepthAttachmentInitialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
			VkImageLayout m_TargetDepthAttachmentFinalLayout = VK_IMAGE_LAYOUT_UNDEFINED;

			std::vector<FrameBufferAttachmentID> m_TargetColorAttachmentIDs;
			FrameBufferAttachmentID m_TargetDepthAttachmentID = InvalidFrameBufferAttachmentID;
			std::vector<FrameBufferAttachmentID> m_SampledAttachmentIDs;

			VkFormat m_ColorAttachmentFormat = VK_FORMAT_UNDEFINED;
			VkFormat m_DepthAttachmentFormat = VK_FORMAT_UNDEFINED;

			VDeleter<VkRenderPass> m_RenderPass;
			FrameBuffer* m_FrameBuffer = nullptr;
			const char* m_Name = nullptr;

			// Points at a valid command buffer while this render pass is being recorded into (Between calls to Begin/End)
			VkCommandBuffer m_ActiveCommandBuffer = VK_NULL_HANDLE;

		};
	} // namespace vk
} // namespace flex

#endif // COMPILE_VULKAN